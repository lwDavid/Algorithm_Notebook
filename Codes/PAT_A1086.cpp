#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int n, temp, pre[31], in[31], pre_index = 1, in_index = 1;
string str;
stack<int> stk;
struct node {
    int lchild, rchild;
} Nodes[31];
int creat(int preL, int preR, int inL, int inR) {
    if (preL > preR)
        return -1;
    int k = inL;
    for (; k <= inR; k++)
        if (in[k] == pre[preL])
            break;
    Nodes[pre[preL]].lchild = creat(preL + 1, preL + k - inL, inL, k - 1);
    Nodes[pre[preL]].rchild = creat(preL + k - inL + 1, preR, k + 1, inR);
    return pre[preL];
}
void postOrder(int root) {
    if (root == -1)
        return;
    postOrder(Nodes[root].lchild);
    postOrder(Nodes[root].rchild);
    printf("%d", root), n--;
    if (n != 0)
        printf(" ");
}
int main() {
    if (scanf("%d", &n))
        for (int i = 0; i < 2 * n; i++) {
            cin >> str;
            if (str == "Push") {
                if (scanf("%d", &temp)) {
                    pre[pre_index++] = temp;
                    stk.push(temp);
                }
            } else {
                in[in_index++] = stk.top();
                stk.pop();
            }
        }
    postOrder(creat(1, n, 1, n));
    printf("\n");
    return 0;
}
