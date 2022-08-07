#include <iostream>
#include <queue>
using namespace std;
int N, L, mi, fo, q, qnum, layer, cnt;
bool G[1001][1001] = {false};
struct Node {
    int v, layer;
    Node(int _v, int _layer) : v(_v), layer(_layer) {}
};
void BFS(int k) {
    bool vis[1001] = {false};
    queue<Node> q;
    Node start(k, 0);
    q.push(start), vis[k] = true;
    cnt = 0;
    while (q.size()) {
        Node top = q.front();
        q.pop();
        for (int i = 1; i <= N && (top.layer < L); i++)
            if (G[top.v][i] && vis[i] == false)
                q.push(Node(i, top.layer + 1)), cnt++, vis[i] = true;
    }
    printf("%d\n", cnt);
}
int main() {
    if (scanf("%d %d", &N, &L))
        for (int i = 1; i <= N; i++) {
            if (scanf("%d", &mi))
                while (mi--)
                    if (scanf("%d", &fo))
                        G[fo][i] = true;
        }
    if (scanf("%d", &q))
        while (q--)
            if (scanf("%d", &qnum))
                BFS(qnum);
    return 0;
}
