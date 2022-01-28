#include <stdio.h>
#include <string.h>
unsigned long long trans(char str[], int radix) {
    int len = strlen(str);
    unsigned long long base = 1, res = 0;
    for (int i = len - 1; i >= 0; i--, base *= radix) {
        if (str[i] >= '0' && str[i] <= '9')
            res += (str[i] - '0') * base;
        else
            res += (str[i] - 'a' + 10) * base;
    }
    return res;
}
unsigned long long findRadix(char a[], char b[], unsigned long long radix) {
    int max = 0, len = strlen(b);
    unsigned long long number = trans(a, radix);
    for (int i = 0; i < len; i++)
        max = (max > b[i]) ? max : b[i];
    if (max >= '0' && max <= '9')
        max -= '0';
    else
        max -= ('a' - 10);
    unsigned long long l = max + 1, r = number + 1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (trans(b, mid) >= number)
            r = mid;
        else
            l = mid + 1;
    }
    if (trans(b, l) == number)
        return l;
    else
        return -1;
}
int main() {
    int tag;
    unsigned long long radix, res;
    char a[11], b[11];
    if (scanf("%s%s%d%lld", a, b, &tag, &radix))
        ;
    if (tag - 1)
        res = findRadix(b, a, radix);
    else
        res = findRadix(a, b, radix);
    if (res == -1)
        printf("Impossible\n");
    else
        printf("%lld\n", res);
    return 0;
}
