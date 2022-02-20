#include <stdio.h>
int main() {
    int size, step;
    int arr[100];
    if (scanf("%d %d", &size, &step))
        ;
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[(i + step) % size]))
            ;
    }
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size-1)
            printf(" ");
    }
    return 0;
}

//Another version that can rotate the array with O(1) extra space when input is the pointer to array.
// #include <stdio.h>
// int gcd(int a, int b) {
//     return !b ? a : gcd(b, a % b);
// }
// int main() {
//     int N, M, a[100];
//     if (scanf("%d %d", &N, &M))
//         for (int i = 0; i < N; i++)
//             if (scanf("%d", &a[i]))
//                 ;
//     M %= N;
//     if (M != 0 && N != 1) {
//         int start = N - M, end = N - M + gcd(N, M) - 1;
//         for (int i = start; i <= end; i++) {
//             int temp = a[i], j = i;
//             do {
//                 a[j] = a[(j - M + N) % N];
//                 j = (j - M + N) % N;
//             } while (j != i);
//             a[(i + M) % N] = temp;
//         }
//     }
//     for (int i = 0; i < N; i++) {
//         printf("%d", a[i]);
//         if (i != N - 1)
//             printf(" ");
//     }
//     printf("\n");
//     return 0;
// }
