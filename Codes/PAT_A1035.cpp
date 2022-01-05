#include <stdio.h>
int main() {
    int N = 0, count = 0, m = 0, flag[1000] = {0};
    char account[1000][2][11] = {0};
    if (scanf("%d", &N))
        ;
    while (N--) {
        if (scanf("%s %s", account[count][0], account[count][1]))
            count++;
    }
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 11; j++) {
            switch (account[i][1][j]) {
                case '1':
                    account[i][1][j] = '@';
                    flag[i] = 1;
                    break;
                case 'l':
                    account[i][1][j] = 'L';
                    flag[i] = 1;
                    break;
                case '0':
                    account[i][1][j] = '%';
                    flag[i] = 1;
                    break;
                case 'O':
                    account[i][1][j] = 'o';
                    flag[i] = 1;
                    break;
            }
        }
    }
    for (int i = 0; i < 1000; i++) {
        if (flag[i])
            m++;
    }
    if (!m) {
        if (count == 1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified", count);
    } else {
        printf("%d\n", m);
        for (int i = 0; i < count; i++)
            if (flag[i]) {
                printf("%s %s\n", account[i][0], account[i][1]);
            }
    }
    return 0;
}
