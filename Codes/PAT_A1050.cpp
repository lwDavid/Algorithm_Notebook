#include <stdio.h>
#include <string.h>
int main() {
    int valid[256] = {0}, len = 0, k = 0;
    char str[10001], c;
    while (scanf("%c", &c) && c != '\n')
        str[k++] = c;
    str[k] = '\0';
    len = strlen(str);
    while (scanf("%c", &c) && c != '\n')
        valid[(int)c] = 1;
    for (int i = 0; i < len; i++)
        if (!valid[(int)str[i]])
            printf("%c", str[i]);
    printf("\n");
    return 0;
}
