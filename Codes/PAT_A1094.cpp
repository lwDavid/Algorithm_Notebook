//The better reference DFS version.
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 110;
vector<int> Node[MAXN];
int hashTable[MAXN] = {0};
void DFS(int index, int level) {
    hashTable[level]++;
    for (int j = 0; j < (int)Node[index].size(); j++)
        DFS(Node[index][j], level + 1);
}
int main() {
    int n, m, parent, k, child;
    if (scanf("%d %d", &n, &m))
        for (int i = 0; i < m; i++)
            if (scanf("%d %d", &parent, &k))
                for (int j = 0; j < k; j++)
                    if (scanf("%d", &child))
                        Node[parent].push_back(child);
    DFS(1, 1);
    int maxLevel = -1, maxValue = 0;
    for (int i = 0; i < MAXN; i++) {
        if (hashTable[i] > maxValue) {
            maxValue = hashTable[i];
            maxLevel = i;
        }
    }
    printf("%d %d\n", maxValue, maxLevel);
    return 0;
}

//My original BFS version.
// #include <cstdio>
// #include <queue>
// #include <vector>
// using namespace std;
// struct node {
//     int depth;
//     vector<int> children;
// };
// int N, M, father, childnum, temp, maxlayer = 1, layer = 1, tot = 1, cnt = 0;
// vector<node> nodes;
// void BFS(int root) {
//     queue<node> q;
//     q.push(nodes[root]);
//     while (!q.empty()) {
//         node t = q.front();
//         if (t.depth == layer)
//             cnt++;
//         else {
//             maxlayer = cnt > tot ? layer : maxlayer;
//             tot = cnt > tot ? cnt : tot;
//             cnt = 1, layer++;
//         }
//         for (int i = 0; i < (int)t.children.size(); i++) {
//             nodes[t.children[i]].depth = t.depth + 1;
//             q.push(nodes[t.children[i]]);
//         }
//         q.pop();
//     }
//     maxlayer = cnt > tot ? layer : maxlayer;
//     tot = cnt > tot ? cnt : tot;
// }
// int main() {
//     if (scanf("%d %d", &N, &M)) {
//         nodes.resize(N + 1), nodes[1].depth = 1;
//         for (int i = 0; i < M; i++)
//             if (scanf("%d %d", &father, &childnum))
//                 for (int j = 0; j < childnum; j++)
//                     if (scanf("%d", &temp))
//                         nodes[father].children.push_back(temp);
//     }
//     BFS(1);
//     printf("%d %d\n", tot, maxlayer);
//     return 0;
// }
