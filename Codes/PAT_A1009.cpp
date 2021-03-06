#include <stdio.h>
int main() {
    int n1, n2, count = 0;
    float coe[1001] = {0.0}, res[2001] = {0.0};
    if (scanf("%d", &n1))
        ;
    for (int i = 1; i <= n1; i++) {
        int a;
        float N;
        if (scanf("%d %f", &a, &N))
            ;
        coe[a] = N;
    }
    if (scanf("%d", &n2))
        ;
    for (int i = 1; i <= n2; i++) {
        int a;
        float N;
        if (scanf("%d %f", &a, &N))
            ;
        for (int j = 0; j <= 1000; j++) {
            if (coe[j] != 0) {
                res[j + a] += coe[j] * N;
            }
        }
    }
    for (int i = 0; i <= 2000; i++) {
        if (res[i] != 0)
            count++;
    }
    printf("%d", count);
    for (int i = 2000; i >= 0; i--) {
        if (res[i] != 0) {
            printf(" %d %.1f", i, res[i]);
        }
    }
    return 0;
}
