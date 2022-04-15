//My version using a BFS algorithm with better memory consume but longer codes.
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int depth;
    vector<int> children;
};
int n = 0, root = -1, temp;
vector<node> nodes;
double price = 0.0, r = 0.0;
void BFS(int root) {
    int maxlayer = -1, cnt = 0;
    queue<node> q;
    q.push(nodes[root]);
    nodes[root].depth = 0;
    while (!q.empty()) {
        node t;
        t = q.front();
        if (t.depth > maxlayer) {
            maxlayer = t.depth;
            cnt = 1;
        } else if (t.depth == maxlayer)
            cnt++;
        for (int i = 0; i < (int)t.children.size(); i++) {
            nodes[t.children[i]].depth = t.depth + 1;
            q.push(nodes[t.children[i]]);
        }
        q.pop();
    }
    printf("%.2lf %d\n", price * pow((1 + 0.01 * r), maxlayer), cnt);
}
int main() {
    if (scanf("%d %lf %lf", &n, &price, &r)) {
        nodes.resize(n);
        for (int i = 0; i < n; i++)
            if (scanf("%d", &temp)) {
                if (temp == -1)
                    root = i;
                else
                    nodes[temp].children.push_back(i);
            }
    }
    BFS(root);
    return 0;
}

//The reference DFS method with concise codes.
// #include <cmath>
// #include <cstdio>
// #include <vector>
// using namespace std;
// const int maxn = 100010;
// vector<int> child[maxn];
// double p, r;
// int n, maxDepth = 0, num = 0;
// void DFS(int index, int depth) {
//     if (child[index].size() == 0) {
//         if (depth > maxDepth) {
//             maxDepth = depth;
//             num = 1;
//         } else if (depth == maxDepth)
//             num++;
//         return;
//     }
//     for (int i = 0; i < (int)child[index].size(); i++)
//         DFS(child[index][i], depth + 1);
// }
// int main() {
//     int father, root = -1;
//     if (scanf("%d %lf %lf", &n, &p, &r))
//         r /= 100;
//     for (int i = 0; i < n; i++) {
//         if (scanf("%d", &father))
//             ;
//         if (father != -1)
//             child[father].push_back(i);
//         else
//             root = i;
//     }
//     DFS(root, 0);
//     printf("%.2f %d\n", p * pow(1 + r, maxDepth), num);
//     return 0;
// }
