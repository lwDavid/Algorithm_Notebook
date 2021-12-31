#include <math.h>
#include <stdio.h>
int main() {
    int A, DA, B, DB, PA = 0, PB = 0;
    if ((scanf("%d %d %d %d", &A, &DA, &B, &DB)) == 4) {
        while (A) {
            if (A % 10 == DA)
                PA = PA * 10 + DA;
            A /= 10;
        }
        while (B) {
            if (B % 10 == DB)
                PB = PB * 10 + DB;
            B /= 10;
        }
    }
    printf("%d", PA + PB);
    return 0;
}
