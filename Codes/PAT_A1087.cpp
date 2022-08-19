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

// The notebook version using Dijkstra.
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <map>
// #include <string>
// using namespace std;
// const int MAXV = 210;
// const int INF = 1000000000;
// int n, m, st, G[MAXV][MAXV], weight[MAXV];
// int d[MAXV], w[MAXV], num[MAXV], pt[MAXV], pre[MAXV];
// bool vis[MAXV] = {false};
// map<string, int> cityToIndex;
// map<int, string> indexToCity;
// void Dijkstra(int s) {
//     fill(d, d + MAXV, INF);
//     memset(w, 0, sizeof(w));
//     memset(num, 0, sizeof(num));
//     memset(pt, 0, sizeof(pt));
//     for (int i = 0; i < n; i++)
//         pre[i] = i;
//     d[s] = 0;
//     w[s] = weight[s];
//     num[s] = 1;
//     for (int i = 0; i < n; i++) {
//         int u = -1, MIN = INF;
//         for (int j = 0; j < n; j++)
//             if (vis[j] == false && d[j] < MIN)
//                 u = j, MIN = d[j];
//         if (u == -1)
//             return;
//         vis[u] = true;
//         for (int v = 0; v < n; v++) {
//             if (vis[v] == false && G[u][v] != INF) {
//                 if (d[u] + G[u][v] < d[v]) {
//                     d[v] = d[u] + G[u][v];
//                     w[v] = w[u] + weight[v];
//                     num[v] = num[u];
//                     pt[v] = pt[u] + 1;
//                     pre[v] = u;
//                 } else if (d[u] + G[u][v] == d[v]) {
//                     num[v] += num[u];
//                     if (w[u] + weight[v] > w[v]) {
//                         w[v] = w[u] + weight[v];
//                         pt[v] = pt[u] + 1;
//                         pre[v] = u;
//                     } else if (w[u] + weight[v] == w[v]) {
//                         double uAvg = 1.0 * (w[u] + weight[v]) / (pt[u] + 1);
//                         double vAvg = 1.0 * w[v] / pt[v];
//                         if (uAvg > vAvg) {
//                             pt[v] = pt[u] + 1;
//                             pre[v] = u;
//                         }
//                     }
//                 }
//             }
//         }
//     }
// }
// void printPath(int v) {
//     if (v == 0) {
//         cout << indexToCity[v];
//         return;
//     }
//     printPath(pre[v]);
//     cout << "->" << indexToCity[v];
// }
// int main() {
//     string start, city1, city2;
//     cin >> n >> m >> start;
//     cityToIndex[start] = 0;
//     indexToCity[0] = start;
//     for (int i = 1; i <= n - 1; i++) {
//         cin >> city1 >> weight[i];
//         cityToIndex[city1] = i;
//         indexToCity[i] = city1;
//     }
//     fill(G[0], G[0] + MAXV * MAXV, INF);
//     for (int i = 0; i < m; i++) {
//         cin >> city1 >> city2;
//         int c1 = cityToIndex[city1], c2 = cityToIndex[city2];
//         cin >> G[c1][c2];
//         G[c2][c1] = G[c1][c2];
//     }
//     Dijkstra(0);
//     int rom = cityToIndex["ROM"];
//     printf("%d %d %d %d\n", num[rom], d[rom], w[rom], w[rom] / pt[rom]);
//     printPath(rom);
//     printf("\n");
//     return 0;
// }

