#include <stdio.h>
#include <string.h>
char odd[13] = {'0', '1', '2', '3', '4', '5', '6',
                '7', '8', '9', 'J', 'Q', 'K'};
int main() {
    int len1, len2, lmax, count = 1;
    char str1[101], str2[101], str1v[101], str2v[101], res[101];
    if (scanf("%s %s", str1, str2))
        ;
    len1 = strlen(str1), len2 = strlen(str2);
    for (int i = 0; i < len1; i++) {
        str1v[len1 - 1 - i] = str1[i];
    }
    for (int i = 0; i < len2; i++) {
        str2v[len2 - 1 - i] = str2[i];
    }
    lmax = len1 > len2 ? len1 : len2;
    if (len1 > len2) {
        for (int i = len2; i < lmax; i++) {
            str2v[i] = '0';
        }
    } else if (len1 < len2) {
        for (int i = len1; i < lmax; i++) {
            str1v[i] = '0';
        }
    }
    for (int i = 0; i < lmax; i++) {
        if (count % 2 == 0) {
            if (str2v[i] - str1v[i] >= 0)
                res[i] = str2v[i] - str1v[i] + '0';
            else
                res[i] = str2v[i] - str1v[i] + 10 + '0';
        } else {
            res[i] = odd[(str1v[i] - '0' + str2v[i] - '0') % 13];
        }
        count++;
    }
    for (int i = lmax - 1; i >= 0; i--) {
        printf("%c", res[i]);
    }
    return 0;
}
