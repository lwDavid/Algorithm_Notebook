#include <stdio.h>
#include <string.h>
char spell[10][6] = {"zero", "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};
int main() {
    int sum = 0, count = 0, flag = 0;
    char str[102], res[3] = {0};
    if (scanf("%s", str))
        ;
    for (int i = 0; i < strlen(str); i++)
        sum += str[i] - '0';
    if (sum == 0) {
        printf("zero");
        return 0;
    }
    do {
        res[count++] = sum % 10;
        sum /= 10;
    } while (sum != 0);
    for (int i = 2; i >= 0; i--) {
        if (res[i] == 0 && flag == 0)
            continue;
        else
            flag++;
        if (flag) {
            if (flag != 1)
                printf(" ");
            printf("%s", spell[(int)res[i]]);
        }
    }
    return 0;
}
