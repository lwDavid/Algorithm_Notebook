#include <stdio.h>
int main() {
    int a_count = 0, b_count = 0, time;
    int a_guess, a_num, b_guess, b_num;
    if (scanf("%d", &time)) {
        while (time--) {
            if ((scanf("%d %d %d %d", &a_guess, &a_num, &b_guess, &b_num))) {
                if (a_num == (a_guess + b_guess) &&
                    b_num != (a_guess + b_guess))
                    b_count++;
                if (a_num != (a_guess + b_guess) &&
                    b_num == (a_guess + b_guess))
                    a_count++;
            }
        }
        printf("%d %d", a_count, b_count);
    }
    return 0;
}
