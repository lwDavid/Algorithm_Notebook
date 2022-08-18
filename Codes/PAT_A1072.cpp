// My initial version using Dijkstra.
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
