#include <stdio.h>
int main() {
    float a, b, c, bet[3];
    for (int i = 0; i < 3; i++) {
        if (scanf("%f %f %f", &a, &b, &c))
            ;
        if (a > b && a > c) {
            bet[i] = a;
            printf("W ");
        } else if (b > c) {
            bet[i] = b;
            printf("T ");
        } else {
            bet[i] = c;
            printf("L ");
        }
    }
    printf("%.2f", (bet[0] * bet[1] * bet[2] * 0.65 - 1) * 2);
    return 0;
}
