#include <stdio.h>
int main() {
    int times;
    int card[55], order[55], newcard[55];
    for (int i = 0; i < 55; i++) {
        newcard[i] = i;
    }
    if (scanf("%d", &times))
        ;
    getchar();
    for (int i = 0; i < 54; i++) {
        scanf("%d", &order[i + 1]);
    }
    while (times--) {
        for (int i = 1; i < 55; i++) {
            card[i] = newcard[i];
        }
        for (int i = 1; i < 55; i++) {
            newcard[order[i]] = card[i];
        }
    }
    for (int i = 1; i < 55; i++) {
        if (newcard[i] <= 13) {
            printf("S%d", newcard[i]);
        } else if (newcard[i] <= 26) {
            printf("H%d", newcard[i] - 13);
        } else if (newcard[i] <= 39) {
            printf("C%d", newcard[i] - 26);
        } else if (newcard[i] <= 52) {
            printf("D%d", newcard[i] - 39);
        } else if (newcard[i] <= 54) {
            printf("J%d", newcard[i] - 52);
        }
        if (i != 54)
            printf(" ");
    }
    return 0;
}
