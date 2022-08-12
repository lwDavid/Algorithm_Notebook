// My initial version using vector.
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    int u, layer;
    Node(int _u, int _layer) : u(_u), layer(_layer) {}
};
int n, a, b, blocks = 0, cnt = 0, max_point = 0, maxH = 0;
bool vis[10001] = {false};
vector<int> G[10001], tmp, res;
vector<int>::iterator it;
void BFS(int i) {
    queue<Node> q;
    Node top(0, 0);
    q.push(Node(i, 1));
    vis[i] = false, cnt++;
    while (!q.empty()) {
        top = q.front();
        if (top.layer > maxH) {
            res.clear();
            res.push_back(top.u);
            maxH = top.layer;
        } else if (top.layer == maxH)
            res.push_back(top.u);
        q.pop();
        for (it = G[top.u].begin(); it != G[top.u].end(); it++)
            if (vis[*it] == true) {
                q.push(Node(*it, top.layer + 1));
                vis[*it] = false, cnt++;
            }
    }
    max_point = top.u;
}
int main() {
    if (scanf("%d", &n))
        for (int i = 1; i < n; i++)
            if (scanf("%d%d", &a, &b))
                G[a].push_back(b), G[b].push_back(a);
    memset(vis, true, n + 1);
    for (int i = 1; i <= n; i++)
        if (vis[i]) {
            BFS(i);
            blocks++;
            break;
        }
    if (cnt == n) {
        memset(vis, true, n + 1);
        Node temp(max_point, 0);
        for (it = res.begin(); it != res.end(); it++)
            tmp.push_back(*it);
        BFS(max_point);
        for (it = tmp.begin(); it != tmp.end(); it++)
            res.push_back(*it);
        sort(res.begin(), res.end());
        for (it = res.begin(); it != res.end(); it++)
            while ((it + 1) != res.end() && *it == *(it + 1))
                res.erase(it);
        for (it = res.begin(); it != res.end(); it++)
            printf("%d\n", *it);
    } else {
        for (int i = 1; i <= n; i++)
            if (vis[i])
                BFS(i), blocks++;
        printf("Error: %d components\n", blocks);
    }
    return 0;
}
