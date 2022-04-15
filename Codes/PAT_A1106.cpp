#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
struct node {
    int depth;
    vector<int> children;
};
int n = 0, temp, childnum, cnt = 0;
vector<node> nodes;
double price = 0.0, r = 0.0, total = 0.0, tempf, low = 0x7fffffffffffffff;
void DFS(int root, int depth) {
    if (nodes[root].children.size() == 0) {
        tempf = price * pow(1 + r, depth);
        if (tempf < low)
            cnt = 1, low = tempf;
        else if (tempf == low)
            cnt++;
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
                for (int j = 0; j < childnum; j++)
                    if (scanf("%d", &temp))
                        nodes[i].children.push_back(temp);
            }
    }
    DFS(0, 0);
    printf("%.4lf %d\n", low, cnt);
    return 0;
}
