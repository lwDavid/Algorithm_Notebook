#include <stdio.h>
#include <string.h>
int main() {
    int i, len, flag;
    char str[256];
    while (scanf("%s", str) != EOF) {
        len = strlen(str), flag = 1;
        for (i = 0; i < len / 2; i++)
            if (str[i] != str[len - 1 - i]) {
                flag = 0;
                break;
            }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
