#include <stdio.h>
#include <string.h>
int main() {
    int a, b, count = 0, len = 0;
    char res[10] = {0};
    if (scanf("%d %d", &a, &b))
        a += b;
    if (a < 0) {
        printf("-");
        a = -a;
    }
    do {
        res[count++] = a % 10 + '0';
        a /= 10;
    } while (a != 0);
    len = strlen(res);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", res[i]);
        if (i > 0 && i % 3 == 0)
            printf(",");
    }
    return 0;
}
