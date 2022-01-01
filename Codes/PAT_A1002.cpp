#include <stdio.h>
int main() {
    int n1, n2, count = 0;
    float coe[1001] = {0.0};
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
        coe[a] += N;
    }
    for (int i = 0; i <= 1000; i++) {
        if (coe[i] != 0.0)
            count++;
    }
    if (count == 0)
        printf("0");
    else {
        printf("%d ", count);
        for (int i = 1000; i >= 0; i--) {
            if (coe[i] != 0.0) {
                printf("%d %.1f", i, coe[i]);
                if (count != 1)
                    printf(" ");
                count--;
            }
        }
    }
    return 0;
}
