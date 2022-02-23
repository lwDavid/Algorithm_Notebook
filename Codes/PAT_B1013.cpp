#include <stdio.h>
int main() {
    int pri[10001] = {0}, p = 0, notpri[104730] = {0};
    notpri[0] = notpri[1] = 1;
    for (int i = 2; i < 104730; i++) {
        if (notpri[i] == 0)
            pri[p++] = i;
        for (int j = 0; j < p && i * pri[j] < 104730; j++) {
            notpri[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    int M, N, count = 0;
    if (scanf("%d %d", &M, &N))
        for (int i = M - 1; i < N; i++) {
            printf("%d", pri[i]);
            count++;
            if (count == 10 || i == N - 1) {
                printf("\n");
                count = 0;
            } else
                printf(" ");
        }
    return 0;
}
