// My initial version using Dijkstra.
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
const int INF = 0x3fffffff;
int n, k, b, e[200], m[200], d[200], a[200], p[200], h[200], G[200][200], w = 1;
string st, city;
bool vis[200] = {false};
map<string, int> c2i;
map<int, string> i2c;
void add(string str, int b) {
    c2i[str] = w;
    e[w] = b;
    i2c[w++] = str;
}
void dijk(int s) {
    fill(d, d + 200, INF);
    d[s] = 0, m[s] = 1;
    for (int i = 0; i < w; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < w; j++)
            if (!vis[j] && d[j] < MIN)
                u = j, MIN = d[j];
        vis[u] = true;
        for (int v = 0; v < n; v++)
            if (!vis[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    p[v] = u;
                    h[v] = h[u] + e[v];
                    a[v] = a[u] + 1;
                    m[v] = m[u];
                } else if (d[u] + G[u][v] == d[v]) {
                    if (h[u] + e[v] > h[v])
                        p[v] = u, h[v] = h[u] + e[v], a[v]++;
                    else if ((h[u] + e[v]) / (a[v] + 1) > h[v] / a[v])
                        p[v] = u, a[v]++;
                    m[v] += m[u];
                }
            }
    }
}
void dfs(int k) {
    if (k == p[k]) {
        cout << i2c[k];
        return;
    } else
        dfs(p[k]);
    cout << "->" << i2c[k];
}
int main() {
    fill(G[0], G[0] + 200 * 200, INF);
    cin >> n >> k >> st;
    for (int i = 0; i < n - 1; i++) {
        cin >> city >> b;
        add(city, b);
    }
    c2i[st] = 0, i2c[0] = st;
    for (int i = 0; i < k; i++) {
        cin >> st >> city >> b;
        G[c2i[st]][c2i[city]] = G[c2i[city]][c2i[st]] = b;
    }
    for (int i = 0; i < w; i++)
        p[i] = i;
    dijk(0);
    b = c2i["ROM"];
    cout << m[b] << ' ' << d[b] << ' ' << h[b] << ' ' << h[b] / a[b] << endl;
    dfs(b);
    printf("\n");
    return 0;
}
