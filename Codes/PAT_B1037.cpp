#include <stdio.h>
int main() {
    int PG, PS, PK, AG, AS, AK, P, A, temp;
    if (scanf("%d.%d.%d %d.%d.%d", &PG, &PS, &PK, &AG, &AS, &AK))
        ;
    P = 17 * 29 * PG + 29 * PS + PK;
    A = 17 * 29 * AG + 29 * AS + AK;
    if (P > A) {
        temp = P;
        P = A;
        A = temp;
        printf("-");
    }
    A -= P;
    printf("%d.%d.%d", A / 493, A % 493 / 29, A % 29);
    return 0;
}
