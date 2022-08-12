// My version using vector & BFS with better complexity in average.
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
        tmp = res;
        BFS(max_point);
        for (it = tmp.begin(); it != tmp.end(); it++)
            res.push_back(*it);
        sort(res.begin(), res.end());
        for (it = res.begin(); it != res.end(); it++)
            if (*it != *(it + 1))
                printf("%d\n", *it);
    } else {
        for (int i = 1; i <= n; i++)
            if (vis[i])
                BFS(i), blocks++;
        printf("Error: %d components\n", blocks);
    }
    return 0;
}

// The notebook version using vector & DFS & disjoint-set.
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <vector>
// using namespace std;
// const int N = 100010;
// vector<int> G[N];
// bool isRoot[N];
// int father[N];
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
// void init(int n) {
//     for (int i = 1; i <= n; i++)
//         father[i] = i;
// }
// int calBlock(int n) {
//     int Block = 0;
//     for (int i = 1; i <= n; i++)
//         isRoot[findFather(i)] = true;
//     for (int i = 1; i <= n; i++)
//         Block += isRoot[i];
//     return Block;
// }
// int maxH = 0;
// vector<int> temp, Ans;
// void DFS(int u, int Height, int pre) {
//     if (Height > maxH) {
//         temp.clear();
//         temp.push_back(u);
//         maxH = Height;
//     } else if (Height == maxH)
//         temp.push_back(u);
//     for (int i = 0; i < (int)G[u].size(); i++) {
//         if (G[u][i] == pre)
//             continue;
//         DFS(G[u][i], Height + 1, u);
//     }
// }
// int main() {
//     int a, b, n;
//     if (scanf("%d", &n))
//         init(n);
//     for (int i = 1; i < n; i++)
//         if (scanf("%d%d", &a, &b)) {
//             G[a].push_back(b);
//             G[b].push_back(a);
//             Union(a, b);
//         }
//     int Block = calBlock(n);
//     if (Block != 1)
//         printf("Error: %d components\n", Block);
//     else {
//         DFS(1, 1, -1);
//         Ans = temp;
//         DFS(Ans[0], 1, -1);
//         for (int i = 0; i < (int)temp.size(); i++)
//             Ans.push_back(temp[i]);
//         sort(Ans.begin(), Ans.end());
//         printf("%d\n", Ans[0]);
//         for (int i = 1; i < (int)Ans.size(); i++)
//             if (Ans[i] != Ans[i - 1])
//                 printf("%d\n", Ans[i]);
//     }
//     return 0;
// }
