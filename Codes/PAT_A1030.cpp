// My initial version with better complexity.
#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 0x3fffffff;
struct edge {
    int d = INF, c = INF;
};
int n, m, s, d, i1, i2, i3, i4, ds[500], ct[500], pre[500];
edge G[500][500];
bool vis[500] = {false};
void output(int d) {
    if (d != pre[d])
        output(pre[d]);
    printf("%d ", d);
}
void dijk(int s) {
    fill(ds, ds + 500, INF);
    fill(ct, ct + 500, INF);
    ds[s] = 0, ct[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++)
            if (!vis[j] && ds[j] < min)
                u = j, min = ds[j];
        vis[u] = true;
        for (int v = 0; v < n; v++)
            if (!vis[v] && G[u][v].d != INF) {
                if (ds[u] + G[u][v].d < ds[v]) {
                    ds[v] = ds[u] + G[u][v].d;
                    ct[v] = ct[u] + G[u][v].c;
                    pre[v] = u;
                } else if (ds[u] + G[u][v].d == ds[v] &&
                           ct[u] + G[u][v].c < ct[v])
                    ct[v] = (ct[u] + G[u][v].c), pre[v] = u;
            }
    }
    output(d), printf("%d %d\n", ds[d], ct[d]);
}
int main() {
    if (scanf("%d%d%d%d", &n, &m, &s, &d))
        for (int i = 0; i < m; i++)
            if (scanf("%d%d%d%d", &i1, &i2, &i3, &i4)) {
                G[i1][i2].d = G[i2][i1].d = i3;
                G[i1][i2].c = G[i2][i1].c = i4;
            }
    for (int i = 0; i < n; i++)
        pre[i] = i;
    dijk(s);
    return 0;
}

// Notebook version using Dijkstra.
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int MAXV = 510;
// const int INF = 1000000000;
// int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
// int d[MAXV], c[MAXV], pre[MAXV];
// bool vis[MAXV] = {false};
// void Dijkstra(int s) {
//     fill(d, d + MAXV, INF);
//     fill(c, c + MAXV, INF);
//     for (int i = 0; i < n; i++)
//         pre[i] = i;
//     d[s] = c[s] = 0;
//     for (int i = 0; i < n; i++) {
//         int u = -1, MIN = INF;
//         for (int j = 0; j < n; j++)
//             if (vis[j] == false && d[j] < MIN) {
//                 u = j;
//                 MIN = d[j];
//             }
//         if (u == -1)
//             return;
//         vis[u] = true;
//         for (int v = 0; v < n; v++)
//             if (vis[v] == false && G[u][v] != INF) {
//                 if (d[u] + G[u][v] < d[v]) {
//                     d[v] = d[u] + G[u][v];
//                     c[v] = c[u] + cost[u][v];
//                     pre[v] = u;
//                 } else if (d[u] + G[u][v] == d[v])
//                     if (c[u] + cost[u][v] < c[v]) {
//                         c[v] = c[u] + cost[u][v];
//                         pre[v] = u;
//                     }
//             }
//     }
// }
// void DFS(int v) {
//     if (v == st) {
//         printf("%d ", v);
//         return;
//     }
//     DFS(pre[v]);
//     printf("%d ", v);
// }
// int main() {
//     if (scanf("%d%d%d%d", &n, &m, &st, &ed))
//         fill(G[0], G[0] + MAXV * MAXV, INF);
//     int u, v;
//     for (int i = 0; i < m; i++)
//         if (scanf("%d%d", &u, &v))
//             if (scanf("%d%d", &G[u][v], &cost[u][v]))
//                 G[v][u] = G[u][v], cost[v][u] = cost[u][v];
//     Dijkstra(st);
//     DFS(ed);
//     printf("%d %d\n", d[ed], c[ed]);
//     return 0;
// }

// Notebook versing using Dijkstra & DFS.
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <vector>
// using namespace std;
// const int MAXV = 510;
// const int INF = 1000000000;
// int n, m, st, ed, G[MAXV][MAXV], cost[MAXV][MAXV];
// int d[MAXV], minCost = INF;
// bool vis[MAXV] = {false};
// vector<int> pre[MAXV];
// vector<int> tempPath, path;
// void Dijkstra(int s) {
//     fill(d, d + MAXV, INF);
//     d[s] = 0;
//     for (int i = 0; i < n; i++) {
//         int u = -1, MIN = INF;
//         for (int j = 0; j < n; j++)
//             if (vis[j] == false && d[j] < MIN) {
//                 u = j;
//                 MIN = d[j];
//             }
//         if (u == -1)
//             return;
//         vis[u] = true;
//         for (int v = 0; v < n; v++) {
//             if (vis[v] == false && G[u][v] != INF) {
//                 if (d[u] + G[u][v] < d[v]) {
//                     d[v] = d[u] + G[u][v];
//                     pre[v].clear();
//                     pre[v].push_back(u);
//                 } else if (d[u] + G[u][v] == d[v])
//                     pre[v].push_back(u);
//             }
//         }
//     }
// }
// void DFS(int v) {
//     if (v == st) {
//         tempPath.push_back(v);
//         int tempCost = 0;
//         for (int i = tempPath.size() - 1; i > 0; i--) {
//             int id = tempPath[i], idNext = tempPath[i - 1];
//             tempCost += cost[id][idNext];
//         }
//         if (tempCost < minCost) {
//             minCost = tempCost;
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
//     if (scanf("%d%d%d%d", &n, &m, &st, &ed))
//         fill(G[0], G[0] + MAXV * MAXV, INF);
//     int u, v;
//     fill(cost[0], cost[0] + MAXV * MAXV, INF);
//     for (int i = 0; i < m; i++)
//         if (scanf("%d%d", &u, &v))
//             if (scanf("%d%d", &G[u][v], &cost[u][v]))
//                 G[v][u] = G[u][v], cost[v][u] = cost[u][v];
//     Dijkstra(st);
//     DFS(ed);
//     for (int i = path.size() - 1; i >= 0; i--)
//         printf("%d ", path[i]);
//     printf("%d %d\n", d[ed], minCost);
//     return 0;
// }
