#include <stdio.h>
int main() {
    int scores[1001] = {0}, N, team, number, score, max = 0, maxi = 0;
    if (scanf("%d", &N))
        ;
    for (int i = 0; i < N; i++)
        if (scanf("%d-%d %d", &team, &number, &score))
            scores[team] += score;
    for (int i = 1; i < 1001; i++)
        if (scores[i] > max) {
            maxi = i;
            max = scores[i];
        }
    printf("%d %d\n", maxi, max);
    return 0;
}
