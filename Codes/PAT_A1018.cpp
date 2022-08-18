// My initial version using Dijkstra & DFS.
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int INF = 0x3fffffff;
int cp, n, st, m, c[501], G[501][501], a, b, t, d[501], go = INF, back = INF;
bool vis[501] = {false};
vector<int> pre[501], path, tempPath;
void dijk(int s) {
    fill(d, d + 501, INF);
    d[s] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j <= n; j++)
            if (vis[j] == false && d[j] < MIN)
                u = j, MIN = d[j];
        vis[u] = true;
        for (int v = 0; v <= n; v++)
            if (vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    pre[v].clear();
                    pre[v].push_back(u);
                    d[v] = d[u] + G[u][v];
                } else if (d[u] + G[u][v] == d[v])
                    pre[v].push_back(u);
            }
    }
}
void dfs(int k) {
    tempPath.push_back(k);
    if (k == 0) {
        a = 0, b = 0;
        for (int i = 0; i < (int)tempPath.size() - 1; i++) {
            a += (cp - c[tempPath[i]]);
            a = a < 0 ? 0 : a;
        }
        b = a;
        for (int i = (int)tempPath.size() - 2; i >= 0; i--)
            b -= cp - c[tempPath[i]];
        if (a < go)
            go = a, back = b, path = tempPath;
        else if (a == go && b < back)
            back = b, path = tempPath;
        return;
    }
    for (int i = 0; i < (int)pre[k].size(); i++)
        dfs(pre[k][i]), tempPath.pop_back();
}
int main() {
    fill(G[0], G[0] + 501 * 501, INF);
    if (scanf("%d%d%d%d", &cp, &n, &st, &m))
        for (int i = 1; i <= n; i++)
            if (scanf("%d", &c[i]))
                ;
    for (int i = 0; i < m; i++)
        if (scanf("%d%d%d", &a, &b, &t))
            G[a][b] = G[b][a] = t;
    cp /= 2;
    dijk(0), dfs(st);
    printf("%d ", go);
    for (int i = path.size() - 1; i > 0; i--)
        printf("%d->", path[i]);
    printf("%d %d\n", path[0], back);
    return 0;
}

// The notebook version.
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <vector>
// using namespace std;
// const int MAXV = 510;
// const int INF = 1000000000;
// int n, m, Cmax, Sp, numPath = 0, G[MAXV][MAXV], weight[MAXV];
// int d[MAXV], minNeed = INF, minRemain = INF;
// bool vis[MAXV] = {false};
// vector<int> pre[MAXV];
// vector<int> tempPath, path;
// void Dijkstra(int s) {
//     fill(d, d + MAXV, INF);
//     d[s] = 0;
//     for (int i = 0; i <= n; i++) {
//         int u = -1, MIN = INF;
//         for (int j = 0; j <= n; j++)
//             if (vis[j] == false && d[j] < MIN) {
//                 u = j;
//                 MIN = d[j];
//             }
//         if (u == -1)
//             return;
//         vis[u] = true;
//         for (int v = 0; v <= n; v++)
//             if (vis[v] == false && G[u][v] != INF) {
//                 if (d[u] + G[u][v] < d[v]) {
//                     d[v] = d[u] + G[u][v];
//                     pre[v].clear();
//                     pre[v].push_back(u);
//                 } else if (d[u] + G[u][v] == d[v])
//                     pre[v].push_back(u);
//             }
//     }
// }
// void DFS(int v) {
//     if (v == 0) {
//         tempPath.push_back(v);
//         int need = 0, remain = 0;
//         for (int i = tempPath.size() - 1; i >= 0; i--) {
//             int id = tempPath[i];
//             if (weight[id] > 0)
//                 remain += weight[id];
//             else {
//                 if (remain > abs(weight[id]))
//                     remain -= abs(weight[id]);
//                 else {
//                     need += abs(weight[id]) - remain;
//                     remain = 0;
//                 }
//             }
//         }
//         if (need < minNeed) {
//             minNeed = need;
//             minRemain = remain;
//             path = tempPath;
//         } else if (need == minNeed && remain < minRemain) {
//             minRemain = remain;
//             path = tempPath;
//         }
//         tempPath.pop_back();
//         return;
//     }
//     tempPath.push_back(v);
//     for (int i = 0; i < (int)pre[v].size(); i++)
//         DFS(pre[v][i]);
//     tempPath.pop_back();
// }
// int main() {
//     int u, v;
//     if (scanf("%d%d%d%d", &Cmax, &n, &Sp, &m))
//         fill(G[0], G[0] + MAXV * MAXV, INF);
//     for (int i = 1; i <= n; i++)
//         if (scanf("%d", &weight[i]))
//             weight[i] -= Cmax / 2;
//     for (int i = 0; i < m; i++)
//         if (scanf("%d%d", &u, &v))
//             if (scanf("%d", &G[u][v]))
//                 G[v][u] = G[u][v];
//     Dijkstra(0);
//     DFS(Sp);
//     printf("%d ", minNeed);
//     for (int i = path.size() - 1; i >= 0; i--) {
//         printf("%d", path[i]);
//         if (i > 0)
//             printf("->");
//     }
//     printf(" %d\n", minRemain);
//     return 0;
// }
