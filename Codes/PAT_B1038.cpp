#include <stdio.h>
int main() {
    int N, K, num[101] = {0}, score, query;
    if (scanf("%d", &N))
        ;
    for (int i = 0; i < N; i++)
        if (scanf("%d", &score))
            num[score]++;
    if (scanf("%d", &K))
        ;
    for (int i = 0; i < K; i++) {
        if (scanf("%d", &query))
            printf("%d", num[query]);
        if (i != K - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
