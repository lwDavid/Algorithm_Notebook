#include <stdio.h>
int main() {
    int N = 0, M = 0, coins[1000] = {0}, coin = 0, i;
    if (scanf("%d %d", &N, &M))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &coin))
                coins[coin]++;
    for (i = 1; i < (M - i); i++)
        if (coins[i] && coins[M - i]) {
            printf("%d %d\n", i, M - i);
            return 0;
        }
    if (i == (M - i) && coins[i] > 1) {
        printf("%d %d\n", i, i);
        return 0;
    }
    printf("No Solution\n");
    return 0;
}

//This problem has a bug. In checkpoint 3, there are coins which have a face value more than 500.
