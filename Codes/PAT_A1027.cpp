#include <stdio.h>
int main() {
    int earth[3], mars[3][2] = {0};
    if (scanf("%d %d %d", &earth[0], &earth[1], &earth[2]))
        ;
    for (int i = 0; i < 3; i++) {
        int n = 0;
        do {
            mars[i][n++] = earth[i] % 13;
            earth[i] /= 13;
        } while (earth[i] != 0);
    }
    printf("#");
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j >= 0; j--) {
            switch (mars[i][j]) {
                case 10:
                    printf("A");
                    break;
                case 11:
                    printf("B");
                    break;
                case 12:
                    printf("C");
                    break;
                default:
                    printf("%d", mars[i][j]);
            }
        }
    }
    return 0;
}
