#include <stdio.h>
#include <string.h>
int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int Z[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main() {
    int N, flag = 1;
    if (scanf("%d", &N))
        ;
    while (N--) {
        int sum = 0;
        char ID[19];
        if (scanf("%s", ID))
            ;
        for (int i = 0; i < 17; i++) {
            if (ID[i] < '0' || ID[i] > '9') {
                printf("%s\n", ID);
                flag = 0;
                goto end;
            }
        }
        for (int i = 0; i < 17; i++) {
            sum += (ID[i] - '0') * weight[i];
        }
        if (Z[sum % 11] != ID[17]) {
            printf("%s\n", ID);
            flag = 0;
            goto end;
        }
    end:
        continue;
    }
    if (flag == 1)
        printf("All passed");
    return 0;
}
