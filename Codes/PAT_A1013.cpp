// My version using adjacency matrix.
#include <cstring>
#include <iostream>
using namespace std;
int N, M, K, a, b, cnt = 0;
bool G[1001][1001] = {false}, vis[1001] = {false};
void DFS(int i) {
    vis[i] = false;
    for (int j = 1; j <= N; j++)
        if (G[i][j] && vis[j])
            DFS(j);
}
int cal(int k) {
    memset(vis, false, sizeof(vis));
    memset(vis, true, N + 1);
    vis[k] = false;
    for (int i = 1; i <= N; i++)
        if (vis[i] == true && i != k)
            DFS(i), cnt++;
    return cnt - 1;
}
int main() {
    if (scanf("%d%d%d", &N, &M, &K))
        for (int i = 0; i < M; i++)
            if (scanf("%d%d", &a, &b))
                G[a][b] = G[b][a] = true;
    for (int i = 0; i < K; i++, cnt = 0)
        if (scanf("%d", &a))
            printf("%d\n", cal(a));
    return 0;
}

// Notebook version using adjacency list.
// #include <cstdio>
// #include <cstring>
// #include <vector>
// using namespace std;
// const int N = 1111;
// vector<int> G[N];
// bool vis[N];
// int currentPoint;
// void dfs(int v) {
//     if (v == currentPoint)
//         return;
//     vis[v] = true;
//     for (int i = 0; i < (int)G[v].size(); i++)
//         if (vis[G[v][i]] == false)
//             dfs(G[v][i]);
// }
// int n, m, k;
// int main() {
//     if (scanf("%d%d%d", &n, &m, &k))
//         for (int i = 0; i < m; i++) {
//             int a, b;
//             if (scanf("%d%d", &a, &b)) {
//                 G[a].push_back(b);
//                 G[b].push_back(a);
//             }
//         }
//     for (int query = 0; query < k; query++) {
//         if (scanf("%d", &currentPoint))
//             memset(vis, false, sizeof(vis));
//         int block = 0;
//         for (int i = 1; i <= n; i++)
//             if (i != currentPoint && vis[i] == false) {
//                 dfs(i);
//                 block++;
//             }
//         printf("%d\n", block - 1);
//     }
//     return 0;
// }

// Notebook version using disjoint-set.
// #include <cstdio>
// #include <vector>
// using namespace std;
// const int N = 1111;
// vector<int> G[N];
// int father[N];
// bool vis[N];
// int findFather(int x) {
//     int a = x;
//     while (x != father[x])
//         x = father[x];
//     while (a != father[a]) {
//         int z = a;
//         a = father[a];
//         father[z] = x;
//     }
//     return x;
// }
// void Union(int a, int b) {
//     int faA = findFather(a);
//     int faB = findFather(b);
//     if (faA != faB)
//         father[faA] = faB;
// }
// void init() {
//     for (int i = 1; i < N; i++) {
//         father[i] = i;
//         vis[i] = false;
//     }
// }
// int n, m, k;
// int main() {
//     if (scanf("%d%d%d", &n, &m, &k))
//         for (int i = 0; i < m; i++) {
//             int a, b;
//             if (scanf("%d%d", &a, &b)) {
//                 G[a].push_back(b);
//                 G[b].push_back(a);
//             }
//         }
//     int currentPoint;
//     for (int query = 0; query < k; query++) {
//         if (scanf("%d", &currentPoint))
//             init();
//         for (int i = 1; i <= n; i++)
//             for (int j = 0; j < (int)G[i].size(); j++) {
//                 int u = i, v = G[i][j];
//                 if (u == currentPoint || v == currentPoint)
//                     continue;
//                 Union(u, v);
//             }
//         int block = 0;
//         for (int i = 1; i <= n; i++) {
//             if (i == currentPoint)
//                 continue;
//             int fa_i = findFather(i);
//             if (vis[fa_i] == false) {
//                 block++;
//                 vis[fa_i] = true;
//             }
//         }
//         printf("%d\n", block - 1);
//     }
//     return 0;
// }
