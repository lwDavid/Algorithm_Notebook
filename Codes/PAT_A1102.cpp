#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int n, k, root;
char l, r;
struct node {
    int lchild = -1, rchild = -1;
} Nodes[15];
void invert(int root) {
    if (root == -1)
        return;
    invert(Nodes[root].lchild);
    invert(Nodes[root].rchild);
    swap(Nodes[root].lchild, Nodes[root].rchild);
    return;
}
int findRoot(int x) {
    int flag = 0;
    for (k = 0; k < n; k++)
        if (Nodes[k].lchild == x || Nodes[k].rchild == x) {
            flag = 1;
            break;
        }
    if (flag)
        return findRoot(k);
    else
        return x;
}
void levelOrder(int root) {
    int cnt = n;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        printf("%d", q.front()), cnt--;
        if (cnt)
            printf(" ");
        else
            printf("\n");
        if (Nodes[q.front()].lchild != -1)
            q.push(Nodes[q.front()].lchild);
        if (Nodes[q.front()].rchild != -1)
            q.push(Nodes[q.front()].rchild);
        q.pop();
    }
}
void inOrder(int root) {
    if (root == -1)
        return;
    inOrder(Nodes[root].lchild);
    printf("%d", root), n--;
    if (n)
        printf(" ");
    else
        printf("\n");
    inOrder(Nodes[root].rchild);
}
int main() {
    if (scanf("%d\n", &n))
        for (int i = 0; i < n; i++)
            if (scanf("%c %c\n", &l, &r)) {
                Nodes[i].lchild = (l == '-') ? -1 : l - '0';
                Nodes[i].rchild = (r == '-') ? -1 : r - '0';
            }
    root = findRoot(0);
    invert(root);
    levelOrder(root);
    inOrder(root);
    return 0;
}
