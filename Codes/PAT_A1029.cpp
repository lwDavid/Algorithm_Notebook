#include <stdio.h>
int main() {
    long A[200000], B[200000], C[400000];
    int m, n, i = 0, j = 0, index = 0;
    if (scanf("%d", &m))
        for (int t = 0; t < m; t++)
            if (scanf("%ld", &A[t]))
                ;
    if (scanf("%d", &n))
        for (int t = 0; t < n; t++)
            if (scanf("%ld", &B[t]))
                ;
    while (i < m && j < n) {
        if ((long)A[i] <= (long)B[j])
            C[index++] = A[i++];
        else
            C[index++] = B[j++];
    }
    while (i < m)
        C[index++] = A[i++];
    while (j < n)
        C[index++] = B[j++];
    printf("%ld\n", C[(index - 1) / 2]);
    return 0;
}
