#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
struct node {
    int data, lchild, rchild;
};
int n, input[100], index = 0, l, r;
node nodes[100];
void creat(int root) {
    if (root == -1)
        return;
    creat(nodes[root].lchild);
    nodes[root].data = input[index++];
    creat(nodes[root].rchild);
}
int main() {
    if (scanf("%d", &n))
        for (int i = 0; i < n; i++)
            if (scanf("%d %d", &nodes[i].lchild, &nodes[i].rchild))
                ;
    for (int i = 0; i < n; i++)
        if (scanf("%d", &input[i]))
            ;
    sort(input, input + n);
    creat(0);
    queue<node> q;
    q.push(nodes[0]);
    while (!q.empty()) {
        printf("%d", q.front().data), n--;
        l = q.front().lchild, r = q.front().rchild;
        if (l != -1)
            q.push(nodes[l]);
        if (r != -1)
            q.push(nodes[r]);
        q.pop();
        n == 0 ? printf("\n") : printf(" ");
    }
    return 0;
}
