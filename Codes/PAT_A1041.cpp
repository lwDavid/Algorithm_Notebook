#include <stdio.h>
int main() {
    int N = 0, bets[10001] = {0}, num = 0, rec[100000] = {0};
    if (scanf("%d", &N))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &num)) {
                bets[num]++;
                rec[i] = num;
            }
    for (int i = 0; i < N; i++)
        if (bets[rec[i]] == 1) {
            printf("%d\n", rec[i]);
            return 0;
        }
    printf("None\n");
    return 0;
}
