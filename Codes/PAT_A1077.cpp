#include <stdio.h>
#include <string.h>
void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char t = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = t;
    }
}
int main() {
    int N, count = 0;
    char lines[100][258], Kuchiguse[258] = {0};
    if (scanf("%d", &N))
        getchar();
    while (N--) {
        if (fgets(lines[count++], 258, stdin))
            ;
    }
    for (int i = 0; i < count; i++) {
        reverse(lines[i]);
    }
    for (int i = 1; i < 258; i++) {
        char t = lines[0][i];
        Kuchiguse[i] = t;
        for (int j = 1; j < count; j++) {
            if (lines[j][i] != t) {
                Kuchiguse[i] = 0;
                goto out;
            }
        }
    }
out:
    if (Kuchiguse[1] == 0) {
        printf("nai");
        return 0;
    }
    Kuchiguse[0] = ' ';
    for (int i = strlen(Kuchiguse) - 1; i > 0; i--) {
        printf("%c", Kuchiguse[i]);
    }
    return 0;
}
