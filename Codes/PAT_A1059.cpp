#include <stdio.h>
int notpri[102] = {0}, pri[26], p = 0;
void init() {
    notpri[0] = notpri[1] = 1;
    for (int i = 2; i < 102; i++) {
        if (notpri[i] == 0)
            pri[p++] = i;
        for (int j = 0; j < p && i * pri[j] < 102; j++) {
            notpri[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}
struct factor {
    int x, cnt;
} fac[10];
int main() {
    init();
    int count = 0;
    long N;
    if (scanf("%ld", &N))
        printf("%ld=", N);
    if (N != 1) {
        for (int i = 0; i < p; i++) {
            if (N % pri[i] == 0) {
                fac[count].x = pri[i];
                fac[count].cnt = 0;
                while (N % pri[i] == 0) {
                    fac[count].cnt++;
                    N /= pri[i];
                }
                count++;
            }
            if (N == 1)
                break;
        }
        if (N != 1) {
            fac[count].x = N;
            fac[count].cnt = 1;
            count++;
        }
        for (int i = 0; i < count; i++) {
            printf("%d", fac[i].x);
            if (fac[i].cnt > 1)
                printf("^%d", fac[i].cnt);
            if (i != count - 1)
                printf("*");
        }
    } else
        printf("1");
    printf("\n");
    return 0;
}
