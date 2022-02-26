#include <stdio.h>
int notpri[100001] = {0}, pri[100001], p = 0;
void init() {
    notpri[0] = notpri[1] = 1;
    for (int i = 2; i < 100001; i++) {
        if (notpri[i] == 0)
            pri[p++] = i;
        for (int j = 0; j < p && i * pri[j] < 100001; j++) {
            notpri[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}
int reverse(int N, int D) {
    int count = 0, num[13], newnum = 0;
    do {
        num[count++] = N % D;
        N /= D;
    } while (N != 0);
    for (int i = 0; i < count; i++)
        newnum = newnum * D + num[i];
    return notpri[newnum] == 0;
}
int main() {
    init();
    int N, D;
    while (scanf("%d", &N) != EOF) {
        if (N < 0)
            break;
        if (scanf("%d", &D) && (notpri[N] == 0) && reverse(N, D))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
