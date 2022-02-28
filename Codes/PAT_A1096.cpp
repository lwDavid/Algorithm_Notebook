#include <math.h>
#include <stdio.h>
int main() {
    int N, sqr, count, M, max = 0, j, pos = 2;
    if (scanf("%d", &N))
        ;
    sqr = sqrt(1.0 * N);
    for (int i = 2; i <= sqr; i++) {
        count = 0;
        M = N;
        j = i;
        while (M % j == 0) {
            count++;
            M /= j;
            j++;
        }
        if (count > max) {
            pos = i;
            max = count;
        }
    }
    if (max == 0)
        printf("1\n%d", N);
    else {
        printf("%d\n", max);
        for (int j = 0; j < max; j++) {
            printf("%d", pos + j);
            if (j != max - 1)
                printf("*");
        }
    }
    printf("\n");
    return 0;
}
