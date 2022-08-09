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
