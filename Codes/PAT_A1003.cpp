// My initial version using Dijkstra & adjacency matrix.
#include <algorithm>
#include <cstdio>
#define INF 0x3fffffff
using namespace std;
int n, m, c1, c2, G[500][500], num[500], team[500], hands[500], d[500], a, b, c;
bool vis[500] = {false};
void dijk(int s) {
    d[s] = 0, num[s] = 1, hands[s] = team[s];
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++)
            if (!vis[j] && d[j] < min)
                u = j, min = d[j];
        vis[u] = true;
        for (int v = 0; v < n; v++)
            if (!vis[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    num[v] = num[u];
                    hands[v] = hands[u] + team[v];
                } else if (d[u] + G[u][v] == d[v]) {
                    num[v] += num[u];
                    if (hands[u] + team[v] > hands[v])
                        hands[v] = hands[u] + team[v];
                }
            }
    }
}
int main() {
    if (scanf("%d%d%d%d", &n, &m, &c1, &c2))
        for (int i = 0; i < n; i++)
            if (scanf("%d", &team[i]))
                ;
    fill(d, d + n, INF);
    fill(G[0], G[0] + n * 500, INF);
    for (int i = 0; i < m; i++)
        if (scanf("%d%d%d", &a, &b, &c))
            G[a][b] = G[b][a] = c;
    dijk(c1);
    printf("%d %d\n", num[c2], hands[c2]);
    return 0;
}

// The notebook version.
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int MAXV = 510;
// const int INF = 1000000000;
// int n, m, st, ed, G[MAXV][MAXV], weight[MAXV];
// int d[MAXV], w[MAXV], num[MAXV];
// bool vis[MAXV] = {false};
// void Dijkstra(int s) {
//     fill(d, d + MAXV, INF);
//     memset(num, 0, sizeof(num));
//     memset(w, 0, sizeof(w));
//     d[s] = 0;
//     w[s] = weight[s];
//     num[s] = 1;
//     for (int i = 0; i < n; i++) {
//         int u = -1, MIN = INF;
//         for (int j = 0; j < n; j++) {
//             if (vis[j] == false && d[j] < MIN) {
//                 u = j;
//                 MIN = d[j];
//             }
//         }
//         if (u == -1)
//             return;
//         vis[u] = true;
//         for (int v = 0; v < n; v++) {
//             if (vis[v] == false && G[u][v] != INF) {
//                 if (d[u] + G[u][v] < d[v]) {
//                     d[v] = d[u] + G[u][v];
//                     w[v] = w[u] + weight[v];
//                     num[v] = num[u];
//                 } else if (d[u] + G[u][v] == d[v]) {
//                     if (w[u] + weight[v] > w[v]) {
//                         w[v] = w[u] + weight[v];
//                     }
//                     num[v] += num[u];
//                 }
//             }
//         }
//     }
// }
// int main() {
//     if (scanf("%d%d%d%d", &n, &m, &st, &ed))
//         for (int i = 0; i < n; i++)
//             if (scanf("%d", &weight[i]))
//                 ;
//     int u, v;
//     fill(G[0], G[0] + MAXV * MAXV, INF);
//     for (int i = 0; i < m; i++)
//         if (scanf("%d%d", &u, &v))
//             if (scanf("%d", &G[u][v]))
//                 G[v][u] = G[u][v];
//     Dijkstra(st);
//     printf("%d %d\n", num[ed], w[ed]);
//     return 0;
// }
