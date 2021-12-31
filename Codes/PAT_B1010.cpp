#include <stdio.h>
int main() {
    int coe[1000000], pow[1000000], newc, newp, count = 0, flag = 0;
    while (scanf("%d %d", &coe[count], &pow[count]) != EOF) {
        count++;
    }
    for (int i = 0; i < count; i++) {
        if (coe[i] != 0 && pow[i] != 0) {
            newc = coe[i] * pow[i];
            newp = pow[i] - 1;
            printf("%d %d", newc, newp);
            flag = 1;
        }
        if (i != (count - 1) && pow[i + 1] != 0)
            printf(" ");
    }
    if (!flag) {
        printf("0 0");
    }
    return 0;
}
