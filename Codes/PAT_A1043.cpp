#include <cstdio>
using namespace std;
int index = 0, N, num[2][1000], flag = 1;
struct node {
    int data;
    node* lchild;
    node* rchild;
};
node* newNode(int v) {
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}
void insert(node*& root, int x) {
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (x < root->data)
        insert(root->lchild, x);
    else
        insert(root->rchild, x);
}
node* mirror(node* root) {
    if (root == NULL)
        return NULL;
    node* Node = new node;
    Node->data = root->data;
    Node->lchild = mirror(root->rchild);
    Node->rchild = mirror(root->lchild);
    return Node;
}
void preorder(node* root, int arr[2][1000]) {
    if (root == NULL)
        return;
    arr[1][index++] = root->data;
    preorder(root->lchild, arr);
    preorder(root->rchild, arr);
}
void postorder(node* root) {
    if (root == NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d", root->data), N--;
    if (N != 0)
        printf(" ");
}
int main() {
    node *BST = NULL, *rvBST = NULL;
    if (scanf("%d", &N))
        for (int i = 0; i < N; i++) {
            if (scanf("%d", &num[0][i]))
                ;
            insert(BST, num[0][i]);
        }
    preorder(BST, num);
    for (int i = 0; i < N; i++)
        if (num[0][i] != num[1][i]) {
            index = 0, flag = 2;
            rvBST = mirror(BST);
            preorder(rvBST, num);
            for (int j = 0; j < N; j++)
                if (num[0][j] != num[1][j]) {
                    flag = 0;
                    break;
                }
            break;
        }
    if (!flag)
        printf("NO");
    else {
        printf("YES\n");
        if (flag == 1)
            postorder(BST);
        else
            postorder(rvBST);
    }
    printf("\n");
    return 0;
}
