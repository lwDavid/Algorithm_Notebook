#include <math.h>
#include <stdio.h>
int main() {
    int column, row;
    char C;
    if (scanf("%d %c", &column, &C))
        ;
    if (column % 2 == 0)
        row = column / 2;
    else
        row = (column + 1) / 2;
    for (int i = 1; i <= row; i++) {
        if (i == 1 || i == row) {
            for (int j = 1; j <= column; j++)
                printf("%c", C);
        } else {
            printf("%c", C);
            for (int j = 1; j <= column - 2; j++)
                printf(" ");
            printf("%c", C);
        }
        printf("\n");
    }
    return 0;
}
