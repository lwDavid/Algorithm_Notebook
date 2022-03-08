#include <algorithm>
#include <cstdio>
using namespace std;
struct Node {
    int key, next, add, flag = 0;
} list[100000];
bool cmp(Node a, Node b) {
    if (a.flag != b.flag)
        return a.flag > b.flag;
    else
        return a.key < b.key;
}
int main() {
    int N, iadd, ikey, next_add, head, M = 0;
    if (scanf("%d %d", &N, &head)) {
        if (head == -1)
            printf("0 -1\n");
        else {
            while (N--)
                if (scanf("%d %d %d", &iadd, &ikey, &next_add)) {
                    list[iadd].add = iadd;
                    list[iadd].key = ikey;
                    list[iadd].next = next_add;
                }
            for (int i = head; i != -1; i = list[i].next, M++)
                list[i].flag = 1;
            sort(list, list + 100000, cmp);
            printf("%d %05d\n", M, list[0].add);
            for (int i = 0; i < M - 1; i++)
                printf("%05d %d %05d\n", list[i].add, list[i].key,
                       list[i + 1].add);
            printf("%05d %d -1\n", list[M - 1].add, list[M - 1].key);
        }
    }
    return 0;
}
