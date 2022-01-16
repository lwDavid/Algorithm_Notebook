#include <stdio.h>
int main() {
    int num[10] = {0};
    for (int i = 0; i < 10; i++)
        if (scanf("%d", &num[i]))
            ;
    for (int i = 1; i < 10; i++)
        if (num[i]) {
            printf("%d", i);
            num[i]--;
            break;
        }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < num[i]; j++)
            printf("%d", i);
    printf("\n");
    return 0;
}
