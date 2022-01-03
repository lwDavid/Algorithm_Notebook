#include <stdio.h>
int main() {
    int n, B, S, G;
    if (scanf("%d", &n))
        ;
    B = n / 100;
    S = n % 100 / 10;
    G = n % 10;
    for (int i = B; i > 0; i--) {
        printf("B");
    }
    for (int i = S; i > 0; i--) {
        printf("S");
    }
    for (int i = 1; i <= G; i++) {
        printf("%d", i);
    }
    return 0;
}
