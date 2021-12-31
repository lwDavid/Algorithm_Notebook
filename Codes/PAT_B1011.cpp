#include <stdio.h>
int main() {
    int num, count = 1;
    int A, B, C;
    if ((scanf("%d", &num)) == 1) {
        while (num--) {
            if ((scanf("%d %d %d", &A, &B, &C)) == 3) {
                if ((long long int)A + (long long int)B > (long long int)C) {
                    printf("Case #%d: true", count);
                } else {
                    printf("Case #%d: false", count);
                }
                if (num != 0)
                    printf("\n");
                count++;
            }
        }
    }
    return 0;
}
