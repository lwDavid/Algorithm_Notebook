#include <math.h>
#include <stdio.h>
void draw(int n, char C) {
    int k = 2 * n - 1, space = 0;
    for (int i = k; i >= 1; i -= 2) {
        for (int j = 1; j <= space; j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("%c", C);
        printf("\n");
        space++;
    }
    space -= 2;
    for (int i = 3; i <= k; i += 2) {
        for (int j = 1; j <= space; j++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("%c", C);
        printf("\n");
        space--;
    }
}
int main() {
    int t, rank, num;
    char C;
    if (scanf("%d %c", &t, &C))
        ;
    rank = sqrt((t + 1) / 2);
    draw(rank, C);
    num = 2 * rank * rank - 1;
    printf("%d", t - num);
    return 0;
}
