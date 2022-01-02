#include <stdio.h>
int main() {
    int n2, N = 0, k = 0, maxk = 0;
    char str[81];
    if (scanf("%s", str))
        ;
    for (int i = 0; str[i]; i++)
        N++;
    for (int i = 3; i <= N; i++) {
        k = (N - i + 2) / 2;
        if (k <= i && k > maxk)
            maxk = k;
    }
    n2 = (N - 2 * maxk) + 2;
    for (int i = 1; i <= maxk; i++) {
        if (i != maxk) {
            printf("%c", str[i - 1]);
            for (int k = 2; k < n2; k++)
                printf(" ");
            printf("%c\n", str[N - i]);
        } else {
            for (int j = maxk - 1; j < maxk - 1 + n2; j++) {
                printf("%c", str[j]);
            }
        }
    }
    return 0;
}
