#include <stdio.h>
int main() {
    int A, B, D, res[40], num = 0;
    if (scanf("%d %d %d", &A, &B, &D))
        ;
    A += B;
    do {
        res[num++] = A % D;
        A /= D;
    } while (A != 0);
    ;
    for (int i = num - 1; i >= 0; i--) {
        printf("%d", res[i]);
    }
    return 0;
}
