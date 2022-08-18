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
