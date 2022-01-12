#include <stdio.h>
#include <string.h>
int main() {
    int len = 0, num[256] = {0}, max = 0, k = 0;
    char str[1001];
    if (fgets(str, 1001, stdin))
        len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            num[(int)str[i] + 32]++;
        if (str[i] >= 'a' && str[i] <= 'z')
            num[(int)str[i]]++;
    }
    for (int i = 'a'; i <= 'z'; i++)
        max = (num[i] > max) ? num[i] : max;
    for (k = 'a'; num[k] != max; k++)
        ;
    printf("%c %d\n", k, max);
    return 0;
}
