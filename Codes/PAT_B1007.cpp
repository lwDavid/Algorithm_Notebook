#include <stdio.h>
int main() {
    int pri[9593] = {0}, p = 0, notpri[100004] = {0}, count = 0, N;
    notpri[0] = notpri[1] = 1;
    for (int i = 2; i < 100004; i++) {
        if (notpri[i] == 0)
            pri[p++] = i;
        for (int j = 0; j < p && i * pri[j] < 100004; j++) {
            notpri[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    if (scanf("%d", &N))
        for (int i = 0; pri[i + 1] <= N; i++)
            if (pri[i + 1] - pri[i] == 2)
                count++;
    printf("%d\n", count);
    return 0;
}
