#include <stdio.h>
struct Node {
    char c;
    int next, visit;
} list[100000];
int main() {
    int Ahead, Bhead, N, add, next_add, flag = 0;
    char letter;
    if (scanf("%d %d %d", &Ahead, &Bhead, &N))
        while (N--)
            if (scanf("%d %c %d", &add, &letter, &next_add))
                list[add].c = letter, list[add].next = next_add;
    if (Ahead == Bhead)
        printf("%05d\n", Ahead);
    else {
        for (int i = Ahead; i != -1; i = list[i].next)
            list[i].visit = 1;
        for (int i = Bhead; i != -1; i = list[i].next)
            if (list[i].visit == 1) {
                printf("%05d\n", i);
                flag = 1;
                break;
            }
        if (!flag)
            printf("-1\n");
    }
    return 0;
}
