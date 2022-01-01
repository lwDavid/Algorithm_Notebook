#include <stdio.h>
struct Student {
    char name[11];
    char id[11];
    short score;
} temp, min, max;
int main() {
    int n;
    if (scanf("%d", &n))
        ;
    min.score = 101;
    max.score = -1;
    for (int i = 0; i < n; i++) {
        if (scanf("%s %s %hd", temp.name, temp.id, &temp.score))
            ;
        if (temp.score < min.score)
            min = temp;
        if (temp.score > max.score)
            max = temp;
    }
    printf("%s %s\n", max.name, max.id);
    printf("%s %s", min.name, min.id);
    return 0;
}
