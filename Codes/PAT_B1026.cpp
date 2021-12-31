#include <stdio.h>
int main() {
    int C1, C2, seconds;
    if ((scanf("%d %d", &C1, &C2)) == 2) {
        double time = (C2 - C1) / 100.0;
        seconds = (int)(time + 0.5);
        printf("%02d:%02d:%02d", seconds / 3600, seconds % 3600 / 60,
               seconds % 60);
    }
    return 0;
}
