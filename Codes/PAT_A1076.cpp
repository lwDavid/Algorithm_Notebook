// Adjacency list version, with a better time complexity.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    int v, layer;
    Node(int _v, int _layer) : v(_v), layer(_layer) {}
};
int N, L, mi, fo, q, qnum, layer, cnt;
vector<Node> Adj[1001];
void BFS(int k) {
    bool vis[1001] = {false};
    queue<Node> q;
    q.push(Node(k, 0)), vis[k] = true, cnt = 0;
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        for (int i = 0; i < (int)Adj[top.v].size(); i++) {
            Node next = Adj[top.v][i];
            next.layer = top.layer + 1;
            if (!vis[next.v] && next.layer <= L)
                q.push(next), cnt++, vis[next.v] = true;
        }
    }
    printf("%d\n", cnt);
}
int main() {
    if (scanf("%d %d", &N, &L))
        for (int i = 1; i <= N; i++)
            if (scanf("%d", &mi))
                while (mi--)
                    if (scanf("%d", &fo))
                        Adj[fo].push_back(Node(i, 0));
    if (scanf("%d", &q))
        while (q--)
            if (scanf("%d", &qnum))
                BFS(qnum);
    return 0;
}

// My initial adjacency matrix version, performs badly when the scale is big.
// #include <iostream>
// #include <queue>
// using namespace std;
// int N, L, mi, fo, q, qnum, layer, cnt;
// bool G[1001][1001] = {false};
// struct Node {
//     int v, layer;
//     Node(int _v, int _layer) : v(_v), layer(_layer) {}
// };
// void BFS(int k) {
//     bool vis[1001] = {false};
//     queue<Node> q;
//     q.push(Node(k, 0)), vis[k] = true;
//     cnt = 0;
//     while (q.size()) {
//         Node top = q.front();
//         q.pop();
//         for (int i = 1; i <= N && (top.layer < L); i++)
//             if (G[top.v][i] && vis[i] == false)
//                 q.push(Node(i, top.layer + 1)), cnt++, vis[i] = true;
//     }
//     printf("%d\n", cnt);
// }
// int main() {
//     if (scanf("%d %d", &N, &L))
//         for (int i = 1; i <= N; i++) {
//             if (scanf("%d", &mi))
//                 while (mi--)
//                     if (scanf("%d", &fo))
//                         G[fo][i] = true;
//         }
//     if (scanf("%d", &q))
//         while (q--)
//             if (scanf("%d", &qnum))
//                 BFS(qnum);
//     return 0;
// }

// The notebook version, using adacency list.
// #include <cstdio>
// #include <cstring>
// #include <queue>
// #include <vector>
// using namespace std;
// const int MAXV = 1010;
// struct Node {
//     int id, layer;
// };
// vector<Node> Adj[MAXV];
// bool inq[MAXV] = {false};
// int BFS(int s, int L) {
//     int numForward = 0;
//     queue<Node> q;
//     Node start;
//     start.id = s;
//     start.layer = 0;
//     q.push(start);
//     inq[start.id] = true;
//     while (!q.empty()) {
//         Node topNode = q.front();
//         q.pop();
//         int u = topNode.id;
//         for (int i = 0; i < (int)Adj[u].size(); i++) {
//             Node next = Adj[u][i];
//             next.layer = topNode.layer + 1;
//             if (inq[next.id] == false && next.layer <= L) {
//                 q.push(next);
//                 inq[next.id] = true;
//                 numForward++;
//             }
//         }
//     }
//     return numForward;
// }
// int main() {
//     Node user;
//     int n, L, numFollow, idFollow;
//     if (scanf("%d%d", &n, &L))
//         for (int i = 1; i <= n; i++) {
//             user.id = i;
//             if (scanf("%d", &numFollow))
//                 for (int j = 0; j < numFollow; j++)
//                     if (scanf("%d", &idFollow))
//                         Adj[idFollow].push_back(user);
//         }
//     int numQuery, s;
//     if (scanf("%d", &numQuery))
//         for (int i = 0; i < numQuery; i++) {
//             memset(inq, false, sizeof(inq));
//             if (scanf("%d", &s)) {
//                 int numForward = BFS(s, L);
//                 printf("%d\n", numForward);
//             }
//         }
//     return 0;
// }
