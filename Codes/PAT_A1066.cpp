#include <algorithm>
#include <cstdio>
using namespace std;
int n, temp;
struct node {
    int data, Height;
    node *lchild, *rchild;
} * root;
node* newNode(int x) {
    node* Node = new node;
    Node->data = x;
    Node->Height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}
int getHeight(node* root) {
    if (root == NULL)
        return 0;
    else
        return root->Height;
}
void updataHeight(node* root) {
    root->Height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBalanceFactor(node* root) {
    return getHeight(root->lchild) - getHeight(root->rchild);
}
void L(node*& root) {
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updataHeight(root);
    updataHeight(temp);
    root = temp;
}
void R(node*& root) {
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updataHeight(root);
    updataHeight(temp);
    root = temp;
}
void insert(node*& root, int x) {
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (x < root->data) {
        insert(root->lchild, x);
        updataHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1)
                R(root);
            else if (getBalanceFactor(root->lchild) == -1)
                L(root->lchild), R(root);
        }
    } else {
        insert(root->rchild, x);
        updataHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1)
                L(root);
            else if (getBalanceFactor(root->rchild) == 1)
                R(root->rchild), L(root);
        }
    }
}
int main() {
    if (scanf("%d", &n))
        for (int i = 0; i < n; i++)
            if (scanf("%d", &temp))
                insert(root, temp);
    printf("%d", root->data);
    return 0;
}
