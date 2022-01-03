#include <stdio.h>
#include <string.h>
int main() {
    int len, sum = 0, res[3] = {0}, count = 0;
    char str[102];
    char PinYin[10][5] = {"ling", "yi",  "er", "san", "si",
                          "wu",   "liu", "qi", "ba",  "jiu"};
    if (scanf("%s", str))
        ;
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        sum += (str[i] - '0');
    }
    do {
        res[count++] = sum % 10;
        sum /= 10;
    } while (sum != 0);
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", PinYin[res[i]]);
        if (i != 0)
            printf(" ");
    }
    return 0;
}
