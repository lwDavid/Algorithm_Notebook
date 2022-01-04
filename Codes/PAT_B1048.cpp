#include <stdio.h>
#include <string.h>
char odd[13] = {'0', '1', '2', '3', '4', '5', '6',
                '7', '8', '9', 'J', 'Q', 'K'};
void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char t = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = t;
    }
}
int main() {
    int len1 = 0, len2 = 0, lmax, count = 1;
    char str1[101] = {0}, str2[101] = {0}, res[101] = {0};
    if (scanf("%s %s", str1, str2))
        len1 = strlen(str1), len2 = strlen(str2);
    lmax = len1 > len2 ? len1 : len2;
    reverse(str1), reverse(str2);
    if (len1 > len2)
        for (int i = len2; i < lmax; i++)
            str2[i] = '0';
    else
        for (int i = len1; i < lmax; i++)
            str1[i] = '0';
    for (int i = 0; i < lmax; i++, count++)
        if (count % 2 == 0)
            res[i] = (str2[i] - str1[i] >= 0) ? str2[i] - str1[i] + '0'
                                              : str2[i] - str1[i] + 10 + '0';
        else
            res[i] = odd[(str1[i] - '0' + str2[i] - '0') % 13];
    reverse(res);
    printf("%s", res);
    return 0;
}
