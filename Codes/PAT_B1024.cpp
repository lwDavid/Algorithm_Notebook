#include <stdio.h>
#include <string.h>
int main() {
    int Epos = 0, exp, i = 0, len;
    char str[10000];
    while ((str[i] = getchar())) {
        if (str[i] == 'E') {
            Epos = i;
            break;
        }
        i++;
    }
    len = strlen(str) - 4;
    if (scanf("%d", &exp))
        ;
    if (str[0] == '-')
        printf("-");
    if (exp == 0) {
        for (int i = 1; i < Epos; i++) {
            printf("%c", str[i]);
        }
        return 0;
    }
    if (exp < 0) {
        exp = -exp;
        printf("0.");
        for (int i = 1; i < exp; i++) {
            printf("0");
        }
        for (int i = 1; i < Epos; i++) {
            if (str[i] == '.')
                continue;
            printf("%c", str[i]);
        }
    } else if (exp >= len) {
        for (int i = 1; i < Epos; i++) {
            if (str[i] == '.')
                continue;
            printf("%c", str[i]);
        }
        exp -= len;
        for (int i = 0; i < exp; i++) {
            printf("0");
        }
    } else {
        int dot = 3 + exp;
        for (int i = 1; i < Epos; i++) {
            if (str[i] == '.') {
                continue;
            }
            if (i == dot)
                printf(".");
            printf("%c", str[i]);
        }
    }
    return 0;
}
