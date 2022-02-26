#include <math.h>
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
    int count = 0;
    char num[13];
    do {
        num[count++] = N % D;
        N /= D;
    } while (N != 0);
    int newnum = 0, len = count;
    for (int i = len - 1, j = 0; i >= 0; i--, j++)
        newnum += num[i] * pow(D, j);
    return notpri[newnum] == 0;
}
int main() {
    init();
    int N, D;
    if (scanf("%d", &N))
        while (N >= 0) {
            if (scanf("%d", &D))
                ;
            if ((notpri[N] == 0) && reverse(N, D))
                printf("Yes\n");
            else
                printf("No\n");
            if (scanf("%d", &N))
                ;
        }
    return 0;
}
