#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct node {
    int depth;
    vector<int> children;
};
int n, m, father, childnum, temp, layer = 1, cnt = 0;
vector<node> nodes;
void BFS(int root) {
    queue<node> q;
    q.push(nodes[root]);
    while (!q.empty()) {
        node t = q.front();
        if (t.depth == layer) {
            if (t.children.size() == 0)
                cnt++;
        } else {
            printf("%d ", cnt);
            cnt = t.children.size() == 0 ? 1 : 0;
            layer++;
        }
        for (int i = 0; i < (int)t.children.size(); i++) {
            nodes[t.children[i]].depth = t.depth + 1;
            q.push(nodes[t.children[i]]);
        }
        q.pop();
    }
    printf("%d\n", cnt);
}
int main() {
    if (scanf("%d %d", &n, &m)) {
        nodes.resize(n + 1);
        for (int i = 0; i < m; i++)
            if (scanf("%d %d", &father, &childnum))
                for (int j = 0; j < childnum; j++)
                    if (scanf("%d", &temp))
                        nodes[father].children.push_back(temp);
    }
    nodes[1].depth = 1;
    BFS(1);
    return 0;
}
