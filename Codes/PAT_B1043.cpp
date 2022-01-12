#include <stdio.h>
#include <string.h>
int main() {
    int len = 0, letter[6] = {0}, count = 0;
    char str[10001], put[6] = {'P', 'A', 'T', 'e', 's', 't'};
    if (scanf("%s", str))
        len = strlen(str);
    for (int i = 0; i < len; i++)
        switch (str[i]) {
            case 'P':
                letter[0]++, count++;
                break;
            case 'A':
                letter[1]++, count++;
                break;
            case 'T':
                letter[2]++, count++;
                break;
            case 'e':
                letter[3]++, count++;
                break;
            case 's':
                letter[4]++, count++;
                break;
            case 't':
                letter[5]++, count++;
                break;
        }
    while (count)
        for (int i = 0; i < 6; i++)
            if (letter[i]) {
                printf("%c", put[i]);
                letter[i]--, count--;
            }
    printf("\n");
    return 0;
}
