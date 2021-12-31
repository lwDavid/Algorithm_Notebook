#include <stdio.h>
#include <string.h>

int main() {
    int turns, draw = 0;
    int Awin[3] = {0}, Bwin[3] = {0};
    char A, B;
    if (scanf("%d", &turns))
        ;
    while (turns--) {
        if ((scanf("\n%c %c", &A, &B)) == 2)
            ;
        if (A == B)
            draw++;
        if (A == 'B' && B == 'C')
            Awin[0]++;
        else if (A == 'B' && B == 'J')
            Bwin[2]++;
        else if (A == 'C' && B == 'B')
            Bwin[0]++;
        else if (A == 'C' && B == 'J')
            Awin[1]++;
        else if (A == 'J' && B == 'B')
            Awin[2]++;
        else if (A == 'J' && B == 'C')
            Bwin[1]++;
    }
    printf("%d %d %d\n", (Awin[0] + Awin[1] + Awin[2]), draw,
           (Bwin[0] + Bwin[1] + Bwin[2]));
    printf("%d %d %d\n", (Bwin[0] + Bwin[1] + Bwin[2]), draw,
           (Awin[0] + Awin[1] + Awin[2]));
    int max1 = 0, max2 = 0;
    for (int i = 0; i < 3; i++) {
        if (Awin[i] > Awin[max1])
            max1 = i;
        if (Bwin[i] > Bwin[max2])
            max2 = i;
    }
    switch (max1) {
        case 0:
            printf("B ");
            break;
        case 1:
            printf("C ");
            break;
        case 2:
            printf("J ");
            break;
    }
    switch (max2) {
        case 0:
            printf("B");
            break;
        case 1:
            printf("C");
            break;
        case 2:
            printf("J");
            break;
    }
    return 0;
}
