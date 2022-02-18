//The most stupid code I have written. Terrible logic.
#include <stdio.h>
#include <string.h>
int check_2(int a, int b, int c) {
    if (b == 1) {
        if (a == c)
            return 1;
        else
            return 0;
    } else
        while (b > 1) {
            c -= a;
            b--;
            if (c < 0)
                return 0;
            return check_2(a, b, c);
        }
    return 0;
}
void check(char str[]) {
    int len = strlen(str), count[3] = {0};
    for (int i = 0; i < len; i++)
        if (str[i] == 'P')
            count[0]++;
        else if (str[i] == 'A')
            count[1]++;
        else if (str[i] == 'T') {
            count[2]++;
            if (count[0] == 0) {
                printf("NO");
                return;
            }
        } else {
            printf("NO");
            return;
        }
    if (count[0] != 1 || count[2] != 1 || !count[1]) {
        printf("NO");
        return;
    }
    int a = 0, b = 0, c = 0, i = 0;
    while (str[i] != 'P') {
        a++;
        i++;
    }
    i++;
    while (str[i] != 'T') {
        b++;
        i++;
    }
    i++;
    while (i < len) {
        c++;
        i++;
    }
    if (check_2(a, b, c))
        printf("YES");
    else
        printf("NO");
}
int main() {
    int n;
    char str[101];
    if (scanf("%d", &n))
        while (n--) {
            if (scanf("%s", str))
                check(str);
            if (n != 0)
                printf("\n");
        }
    return 0;
}
