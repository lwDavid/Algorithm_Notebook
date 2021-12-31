#include <stdio.h>

int main() {
    int T;
    long long A, B, C, res;
    if (scanf("%d", &T))
        ;
    for (int i = 1; i <= T; i++) {
        if (scanf("%lld %lld %lld", &A, &B, &C))
            ;
        res = A + B;
        if (A > 0 && B > 0 && res < 0) {
            printf("Case #%d: true", i);
        } else if (A < 0 && B < 0 && res >= 0) {
            printf("Case #%d: false", i);
        } else if (res > C) {
            printf("Case #%d: true", i);
        } else {
            printf("Case #%d: false", i);
        }
        if (i != T)
            printf("\n");
    }
    return 0;
}
