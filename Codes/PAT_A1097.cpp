// Maintaining two linklists.
#include <math.h>
#include <stdio.h>
struct Node {
    int key, next = -1;
} node[100000];
int main() {
    int start, N, add, k, nxt, hashTable[10001] = {0}, p, pre, count = 0, mhead;
    if (scanf("%d %d", &start, &N))
        while (N--)
            if (scanf("%d %d %d", &add, &k, &nxt))
                node[add].key = k, node[add].next = nxt;
    for (p = pre = start; node[p].next != -1;)
        if (hashTable[abs(node[p].key)] == 0) {
            hashTable[abs(node[p].key)] = 1;
            pre = p;
            p = node[p].next;
        } else {
            if (!count) {
                count++;
                mhead = p;
                k = mhead;
                node[pre].next = node[p].next;
                p = node[p].next;
                node[k].next = -1;
                continue;
            }
            node[pre].next = node[p].next;
            node[k].next = p;
            p = node[p].next;
            k = node[k].next;
            node[k].next = -1;
        }
    if (hashTable[abs(node[p].key)] == 1) {
        node[pre].next = -1;
        node[k].next = p;
        node[p].next = -1;
    }
    for (; node[start].next != -1; start = node[start].next)
        printf("%05d %d %05d\n", start, node[start].key, node[start].next);
    printf("%05d %d -1\n", start, node[start].key);
    if (count) {
        for (; node[mhead].next != -1; mhead = node[mhead].next)
            printf("%05d %d %05d\n", mhead, node[mhead].key, node[mhead].next);
        printf("%05d %d -1\n", mhead, node[mhead].key);
    }
    return 0;
}

//Using vector for a more concise code, but with a worse memory consuming.
// #include <cmath>
// #include <cstdio>
// #include <vector>
// using namespace std;
// struct Node {
//     int key, next = -1, add;
// } node[100000];
// int main() {
//     vector<Node> dupli;
//     int start, N, add, k, nxt, hashTable[10001] = {0}, p, pre;
//     if (scanf("%d %d", &start, &N))
//         while (N--)
//             if (scanf("%d %d %d", &add, &k, &nxt))
//                 node[add].key = k, node[add].next = nxt, node[add].add = add;
//     for (p = pre = start; p != -1; p = node[p].next)
//         if (hashTable[abs(node[p].key)] == 0) {
//             hashTable[abs(node[p].key)] = 1;
//             pre = p;
//         } else {
//             Node temp = node[p];
//             dupli.push_back(temp);
//             node[pre].next = node[p].next;
//         }
//     for (; node[start].next != -1; start = node[start].next)
//         printf("%05d %d %05d\n", start, node[start].key, node[start].next);
//     printf("%05d %d -1\n", start, node[start].key);
//     if (dupli.size() > 0) {
//         vector<Node>::iterator it = dupli.begin();
//         for (; (it + 1) != dupli.end(); it++)
//             printf("%05d %d %05d\n", (*it).add, (*it).key, (*(it + 1)).add);
//         printf("%05d %d -1\n", (*it).add, (*it).key);
//     }
//     return 0;
// }
