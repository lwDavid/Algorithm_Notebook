#include <stdio.h>
#include <string.h>
int main() {
    char str[1001];
    int count[10] = {0}, len, k = 0;
    if (scanf("%s", str))
        ;
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        count[str[i] - 48]++;
    }
    for (int i = 0; i < 10; i++) {
        if (count[i])
            k++;
    }
    for (int i = 0; i < 10; i++) {
        if (count[i]) {
            printf("%d:%d", i, count[i]);
            k--;
            if (k)
                printf("\n");
        }
    }
    return 0;
}
