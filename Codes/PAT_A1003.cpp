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
