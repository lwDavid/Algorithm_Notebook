#include <stdio.h>
int main() {
    int N, b, res[31], num = 0, flag = 1;
    if (scanf("%d %d", &N, &b))
        ;
    do {
        res[num++] = N % b;
        N /= b;
    } while (N != 0);
    ;
    for (int i = 0; i < (num / 2); i++) {
        if (res[i] != res[num - 1 - i]) {
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("Yes\n");
    else
        printf("No\n");
    for (int i = num - 1; i >= 0; i--) {
        printf("%d", res[i]);
        if (i != 0)
            printf(" ");
    }
    return 0;
}
