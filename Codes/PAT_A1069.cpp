#include <algorithm>
#include <cstdio>
void load(int A[], int num) {
    for (int i = 1000, j = 0, t = num; i >= 1; i /= 10) {
        A[j++] = t / i;
        t %= i;
    }
    std::sort(A, A + 4);
}
int main() {
    int num[4], number, A = 0, B = 0, C = 0, i, k;
    if (scanf("%d", &number))
        load(num, number);
    while (1) {
        for (i = 1, k = 0, A = 0, B = 0; i <= 1000; i *= 10, k++) {
            A += i * num[k];
            B += 1000 / i * num[k];
        }
        C = A - B;
        load(num, C);
        printf("%04d - %04d = %04d\n", A, B, C);
        if (C == 0 || C == 6174)
            break;
    }
    return 0;
}
