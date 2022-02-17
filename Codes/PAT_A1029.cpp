#include <stdio.h>
int main() {
    int A[200001], B[200001], m, n, i = 0, j = 0, k = 0, pos;
    if (scanf("%d", &m))
        for (int t = 0; t < m; t++)
            if (scanf("%d", &A[t]))
                A[m] = 0x7fffffff;
    if (scanf("%d", &n))
        for (int t = 0; t < n; t++)
            if (scanf("%d", &B[t]))
                B[n] = 0x7fffffff;
    pos = (m + n - 1) / 2;
    while (k < pos) {
        if (A[i] < B[j])
            i++;
        else
            j++;
        k++;
    }
    printf("%d\n", A[i] < B[j] ? A[i] : B[j]);
    return 0;
}
