#include <cstdio>
#include <cstring>
int hash(char t) {
    if (t >= '0' && t <= '9')
        return t - '0';
    else if (t >= 'A' && t <= 'Z')
        return t - 'A' + 10;
    else if (t >= 'a' && t <= 'z')
        return t - 'a' + 10;
    else
        switch (t) {
            case '_':
                return 36;
            case ',':
                return 37;
            case '.':
                return 38;
            case '-':
                return 39;
            case '+':
                return 40;
        }
    return 0;
}
int main() {
    int len1 = 0, len2 = 0, capital = 1, k = 0;
    bool broken[41] = {false};
    char badkey[41], str[100000], c;
    while (scanf("%c", &c) && c != '\n')
        badkey[k++] = c;
    badkey[k] = '\0';
    len1 = strlen(badkey);
    k = 0;
    while (scanf("%c", &c) && c != '\n')
        str[k++] = c;
    str[k] = '\0';
    len2 = strlen(str);
    for (int i = 0; i < len1; i++)
        broken[hash(badkey[i])] = true;
    if (broken[40])
        capital = 0;
    for (int i = 0; i < len2; i++) {
        c = str[i];
        if (!broken[hash(c)]) {
            if (c >= 'A' && c <= 'Z' && !capital)
                continue;
            else
                printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}
