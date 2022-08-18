// My initial version using Dijkstra and adjacency list, has better complexities in average.
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n, m, k, ds, d[1011], dis;
char s1[5], s2[5];
bool vis[1011];
const int INF = 0x3fffffff;
struct gas {
    int id, minDis;
    double aver = 0.0;
    gas(int _id, int _minDis, double _aver)
        : id(_id), minDis(_minDis), aver(_aver) {}
};
struct Node {
    int u, d;
    Node(int _u, int _d) : u(_u), d(_d) {}
    bool operator==(const int& k) { return (u == k); }
};
bool cmp(gas A, gas B) {
    if (A.minDis != B.minDis)
        return A.minDis > B.minDis;
    else if (A.aver != B.aver)
        return A.aver < B.aver;
    else
        return A.id < B.id;
}
vector<Node> G[1011];
vector<Node>::iterator it;
vector<gas> res;
int change(char s[5]) {
    int k = s[0] == 'G' ? 1 : 0, sum = 0, t = 1;
    for (int i = strlen(s) - 1; i >= k; i--, t *= 10)
        sum += (s[i] - 48) * t;
    if (s[0] == 'G')
        sum += n;
    return sum;
}
void dijk(int s) {
    fill(d, d + 1011, INF);
    fill(vis, vis + 1011, false);
    d[s] = 0;
    for (int i = 0; i < m + n; i++) {
        int u = -1, MIN = INF;
        for (int j = 1; j <= m + n; j++)
            if (!vis[j] && d[j] < MIN)
                u = j, MIN = d[j];
        vis[u] = true;
        for (int v = 1; v <= m + n; v++) {
            it = find(G[u].begin(), G[u].end(), v);
            if (!vis[v] && it != G[u].end())
                if (d[u] + it->d < d[v])
                    d[v] = d[u] + it->d;
        }
    }
    int min_d = INF, max_d = 0;
    double aver = 0.0;
    for (int i = 1; i <= n; i++) {
        min_d = d[i] < min_d ? d[i] : min_d;
        max_d = max_d < d[i] ? d[i] : max_d;
        aver += d[i];
    }
    min_d = max_d > ds ? 0 : min_d;
    aver /= n;
    res.push_back(gas(s, min_d, aver));
}
int main() {
    if (scanf("%d%d%d%d", &n, &m, &k, &ds))
        for (int i = 0; i < k; i++)
            if (scanf("%s %s %d", s1, s2, &dis)) {
                int a = change(s1), b = change(s2);
                G[a].push_back(Node(b, dis));
                G[b].push_back(Node(a, dis));
            }
    for (int i = n + 1; i <= m + n; i++)
        dijk(i);
    sort(res.begin(), res.end(), cmp);
    if (res.front().minDis == 0)
        printf("No Solution\n");
    else {
        gas op = res.front();
        printf("G%d\n%.1lf %.1lf", op.id - n, (double)op.minDis, op.aver);
    }
    return 0;
}

// The notebook version, using Dijkstra and adjacency matrix without sort(), faster only in large scale data.
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int MAXV = 1020;
// const int INF = 1000000000;
// int n, m, k, DS, G[MAXV][MAXV];
// int d[MAXV];
// bool vis[MAXV] = {false};
// void Dijkstra(int s) {
//     memset(vis, false, sizeof(vis));
//     fill(d, d + MAXV, INF);
//     d[s] = 0;
//     for (int i = 0; i < n + m; i++) {
//         int u = -1, MIN = INF;
//         for (int j = 1; j <= n + m; j++)
//             if (vis[j] == false && d[j] < MIN) {
//                 u = j;
//                 MIN = d[j];
//             }
//         if (u == -1)
//             return;
//         vis[u] = true;
//         for (int v = 1; v <= n + m; v++)
//             if (vis[v] == false && G[u][v] != INF)
//                 if (d[u] + G[u][v] < d[v])
//                     d[v] = d[u] + G[u][v];
//     }
// }
// int getID(char str[]) {
//     int i = 0, len = strlen(str), ID = 0;
//     while (i < len) {
//         if (str[i] != 'G')
//             ID = ID * 10 + (str[i] - '0');
//         i++;
//     }
//     if (str[0] == 'G')
//         return n + ID;
//     else
//         return ID;
// }
// int main() {
//     int u, v, w;
//     char city1[5], city2[5];
//     if (scanf("%d%d%d%d", &n, &m, &k, &DS))
//         fill(G[0], G[0] + MAXV * MAXV, INF);
//     for (int i = 0; i < k; i++)
//         if (scanf("%s %s %d", city1, city2, &w)) {
//             u = getID(city1);
//             v = getID(city2);
//             G[u][v] = G[v][u] = w;
//         }
//     double ansDis = -1, ansAvg = INF;
//     int ansID = -1;
//     for (int i = n + 1; i <= n + m; i++) {
//         double minDis = INF, avg = 0;
//         Dijkstra(i);
//         for (int j = 1; j <= n; j++) {
//             if (d[j] > DS) {
//                 minDis = -1;
//                 break;
//             }
//             if (d[j] < minDis)
//                 minDis = d[j];
//             avg += 1.0 * d[j] / n;
//         }
//         if (minDis == -1)
//             continue;
//         if (minDis > ansDis) {
//             ansID = i;
//             ansDis = minDis;
//             ansAvg = avg;
//         } else if (minDis == ansDis && avg < ansAvg) {
//             ansID = i;
//             ansAvg = avg;
//         }
//     }
//     if (ansID == -1)
//         printf("No Solution\n");
//     else {
//         printf("G%d\n", ansID - n);
//         printf("%.1f %.1f", ansDis, ansAvg);
//     }
//     return 0;
// }
