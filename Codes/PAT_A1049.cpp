#include <stdio.h>
int main() {
    int N, sum = 0, left, right, now, a = 1;
    if (scanf("%d", &N))
        for (; N / a; a *= 10) {
            left = N / (a * 10);
            right = N % a;
            now = N / a % 10;
            if (now == 0)
                sum += left * a;
            else if (now == 1)
                sum += left * a + right + 1;
            else
                sum += (left + 1) * a;
        }
    printf("%d\n", sum);
    return 0;
}
