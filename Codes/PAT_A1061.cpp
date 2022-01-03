#include <stdio.h>
#include <string.h>
char weekday[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main() {
    int mark = 0;
    char str[4][61];
    for (int i = 0; i < 4; i++) {
        if (scanf("%s", str[i]))
            ;
    }
    for (int i = 0; i < strlen(str[0]); i++) {
        if (str[0][i] == str[1][i] && str[0][i] >= 'A' && str[0][i] <= 'G') {
            printf("%s ", weekday[str[0][i] - 'A']);
            mark = i;
            break;
        }
    }
    for (int i = mark + 1; i < strlen(str[0]); i++) {
        if (str[0][i] == str[1][i] && str[0][i] >= '0' && str[0][i] <= '9') {
            printf("0%c:", str[0][i]);
            break;
        } else if (str[0][i] == str[1][i] && str[0][i] >= 'A' &&
                   str[0][i] <= 'N') {
            printf("%2d:", str[0][i] - 'A' + 10);
            break;
        }
    }
    for (int i = 0; i < strlen(str[2]); i++) {
        if (str[2][i] == str[3][i] && str[2][i] >= 'A' && str[2][i] <= 'z') {
            printf("%02d", i);
            break;
        }
    }
    return 0;
}
