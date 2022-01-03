#include <stdio.h>
#include <string.h>
int main() {
    char str[1001];
    int count[10] = {0}, len;
    if (scanf("%s", str))
        ;
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        count[str[i] - '0']++;
    }
    for (int i = 0; i < 10; i++) {
        if (count[i]) {
            printf("%d:%d\n", i, count[i]);
        }
    }
    return 0;
}
