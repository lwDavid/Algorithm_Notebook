#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int depth, load = 0;
    vector<int> children;
};
int n = 0, root = -1, temp, childnum;
vector<node> nodes;
double price = 0.0, r = 0.0, total = 0.0;
void DFS(int root, int depth) {
    if (nodes[root].children.size() == 0) {
        total += pow(1 + r, depth) * price * nodes[root].load;
        return;
    }
    for (int i = 0; i < (int)nodes[root].children.size(); i++)
        DFS(nodes[root].children[i], depth + 1);
}
int main() {
    if (scanf("%d %lf %lf", &n, &price, &r)) {
        nodes.resize(n), r /= 100;
        for (int i = 0; i < n; i++)
            if (scanf("%d", &childnum)) {
                if (childnum != 0) {
                    for (int j = 0; j < childnum; j++)
                        if (scanf("%d", &temp))
                            nodes[i].children.push_back(temp);
                } else if (scanf("%d", &nodes[i].load))
                    ;
            }
    }
    DFS(0, 0);
    printf("%.1lf\n", total);
    return 0;
}
