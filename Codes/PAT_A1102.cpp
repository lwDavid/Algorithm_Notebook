#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int n, notRoot[11] = {0};
char l, r;
struct node {
    int lchild = -1, rchild = -1;
} Nodes[11];
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
        if (Nodes[q.front()].rchild != -1)
            q.push(Nodes[q.front()].rchild);
        if (Nodes[q.front()].lchild != -1)
            q.push(Nodes[q.front()].lchild);
        q.pop();
    }
}
void inOrder(int root) {
    if (root == -1)
        return;
    inOrder(Nodes[root].rchild);
    printf("%d", root), n--;
    if (n)
        printf(" ");
    else
        printf("\n");
    inOrder(Nodes[root].lchild);
}
int main() {
    if (scanf("%d\n", &n))
        for (int i = 0; i < n; i++)
            if (scanf("%c %c\n", &l, &r)) {
                Nodes[i].lchild = (l == '-') ? -1 : l - '0',
                notRoot[l - '0'] = 1;
                Nodes[i].rchild = (r == '-') ? -1 : r - '0',
                notRoot[r - '0'] = 1;
                ;
            }
    for (int i = 0; i < n; i++)
        if (!notRoot[i]) {
            levelOrder(i);
            inOrder(i);
            break;
        }
    return 0;
}
