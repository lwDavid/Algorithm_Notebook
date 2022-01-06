#include <stdio.h>
char num[10][5] = {"ling", "yi",  "er", "san", "si",
                   "wu",   "liu", "qi", "ba",  "jiu"};
char unit[9][5] = {"", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi"};
int main() {
    int N, count = 0;
    char str[10];
    if (scanf("%d", &N))
        ;
    if (N < 0) {
        printf("Fu ");
        N = -N;
    }
    do {
        str[count++] = N % 10 + '0';
        N /= 10;
    } while (N);
    printf("%s", num[str[count - 1] - '0']);
    if (count != 1)
        printf(" %s", unit[count - 1]);
    int zero = 0, zeronum = 0;
    for (int i = count - 2; i >= 0; i--) {
        if (str[i] == '0') {
            zero = 1;
            zeronum++;
            if (i == 4 && zeronum != 4)
                printf(" Wan");
            continue;
        }
        if (zero) {
            printf(" ling");
            zero = zeronum = 0;
        }
        printf(" %s", num[str[i] - '0']);
        if (i != 0)
            printf(" ");
        printf("%s", unit[i]);
    }
    return 0;
}
