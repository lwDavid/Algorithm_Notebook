#include <stdio.h>
#include <string.h>
int main() {
    int len = 0, letter[6] = {0}, count = 0;
    char str[10001], put[6] = {'P', 'A', 'T', 'e', 's', 't'};
    if (scanf("%s", str))
        len = strlen(str);
    for (int i = 0; i < len; i++)
        for (int j = 0; j < 6; j++)
            if (str[i] == put[j])
                letter[j]++, count++;
    while (count)
        for (int i = 0; i < 6; i++)
            if (letter[i]) {
                printf("%c", put[i]);
                letter[i]--, count--;
            }
    printf("\n");
    return 0;
}
