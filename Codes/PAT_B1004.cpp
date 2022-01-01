#define maxn 1000
#include <stdio.h>
struct Student {
    char name[11];
    char id[11];
    short score;
} list[maxn];
int main() {
    int n, min = 0, max = 0;
    if (scanf("%d", &n))
        ;
    for (int i = 0; i < n; i++) {
        if (scanf("%s %s %hd", list[i].name, list[i].id, &list[i].score))
            ;
        if (list[i].score < list[min].score)
            min = i;
        if (list[i].score > list[max].score)
            max = i;
    }
    printf("%s %s\n", list[max].name, list[max].id);
    printf("%s %s", list[min].name, list[min].id);
    return 0;
}
