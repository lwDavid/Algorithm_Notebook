#include <stdio.h>
#include <queue>
using namespace std;
int post[31], in[31], N;
struct node {
    int data;
    node* lchild;
    node* rchild;
} * Node;
node* creat(int postL, int postR, int inL, int inR) {
    if (postL > postR)
        return NULL;
    node* root = new node;
    root->data = post[postR];
    for (int i = inL; i <= inR; i++)
        if (in[i] == post[postR]) {
            root->lchild = creat(postL, postL + i - inL - 1, inL, i - 1);
            root->rchild = creat(postL + i - inL, postR - 1, i + 1, inR);
            break;
        }
    return root;
}
void level(node* root) {
    if (root == NULL)
        return;
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        Node = Q.front();
        Q.pop();
        printf("%d", Node->data), N--;
        if (N != 0)
            printf(" ");
        if (Node->lchild != NULL)
            Q.push(Node->lchild);
        if (Node->rchild != NULL)
            Q.push(Node->rchild);
    }
}
int main() {
    if (scanf("%d", &N))
        for (int i = 1; i <= N; i++)
            if (scanf("%d", &post[i]))
                ;
    for (int i = 1; i <= N; i++)
        if (scanf("%d", &in[i]))
            ;
    node* root = creat(1, N, 1, N);
    level(root);
    printf("\n");
    return 0;
}
