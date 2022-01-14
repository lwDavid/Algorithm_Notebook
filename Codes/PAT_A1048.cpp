#include <stdio.h>
int main() {
    int N = 0, M = 0, coins[1000] = {0}, coin = 0, i;
    if (scanf("%d %d", &N, &M))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &coin))
                coins[coin]++;
    for (i = 1; i < M; i++)
        if (coins[i] && coins[M - i]) {
            if((i==(M-i))&&coins[i]<2)
                continue;
            printf("%d %d\n", i, M - i);
            return 0;
        }
    printf("No Solution\n");
    return 0;
}
