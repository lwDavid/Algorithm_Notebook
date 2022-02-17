#include <algorithm>
#include <cstdio>
bool same(int A[], int B[], int n) {
    for (int i = 0; i < n; i++)
        if (A[i] != B[i])
            return false;
    return true;
}
void printArr(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
        if (i != n - 1)
            printf(" ");
    }
}
void MergeSort(int A[], int B[], int n) {
    int output = 0;
    for (int step = 2; step / 2 <= n; step *= 2) {
        for (int i = 0; i < n; i += step) {
            int mid = i + step / 2 - 1;
            if (mid + 1 < n)
                std::sort(A + i, A + std::min(i + step, n));
        }
        if (output) {
            printf("Merge Sort\n");
            printArr(A, n);
            return;
        }
        if (same(A, B, n))
            output = 1;
    }
}
void InsertSort(int A[], int B[], int n) {
    int output = 0, C[100];
    for (int i = 0; i < n; i++)
        C[i] = A[i];
    for (int i = 1; i < n; i++) {
        int key = C[i], j = i - 1;
        while ((j >= 0) && (key < C[j])) {
            C[j + 1] = C[j];
            j--;
        }
        C[j + 1] = key;
        if (output) {
            printf("Insertion Sort\n");
            printArr(C, n);
            return;
        }
        if (same(C, B, n))
            output = 1;
    }
    MergeSort(A, B, n);
}
int main() {
    int n, A[100], B[100];
    if (scanf("%d", &n))
        for (int i = 0; i < n; i++)
            if (scanf("%d", &A[i]))
                ;
    for (int i = 0; i < n; i++)
        if (scanf("%d", &B[i]))
            ;
    InsertSort(A, B, n);
    return 0;
}
