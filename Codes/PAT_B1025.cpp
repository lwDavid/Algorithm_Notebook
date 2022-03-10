#include <stdio.h>
struct Node {
    int data, next = -1;
} node[100000];
void reverse(Node node[], int pre, int p) {
    int i = pre, j = node[i].next, out = node[p].next;
    node[i].next = out;
    while (j != out) {
        int temp = node[j].next;
        node[j].next = i;
        i = j;
        j = temp;
    }
}
int main() {
    int head, N, K, add, pre, p, d, n, last = -1, t;
    if (scanf("%d %d %d", &head, &N, &K))
        for (int i = 0; i < N; i++)
            if (scanf("%d %d %d", &add, &d, &n))
                node[add].data = d, node[add].next = n;
    pre = p = head;
    for (int i = 1; i < K; i++)
        head = node[head].next;
    while (p != -1) {
        t = 0;
        for (int i = 1; i < K && node[p].next != -1; i++, t++)
            p = node[p].next;
        int temp = node[p].next;
        if (t + 1 == K)
            reverse(node, pre, p);
        else
            break;
        if (last != -1)
            node[last].next = p;
        last = pre;
        pre = p = temp;
    }
    while (head != -1) {
        if (node[head].next == -1)
            printf("%05d %d -1\n", head, node[head].data);
        else
            printf("%05d %d %05d\n", head, node[head].data, node[head].next);
        head = node[head].next;
    }
    return 0;
}
