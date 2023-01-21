// Simulation. Consumes a lot of memory.
#include <limits.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 9973;
int arr[maxn][maxn];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int k, tmp, m = 1, n = 1, i, j, p, minn = INT_MAX, N;
    vector<int> s;

    if (scanf("%d", &k))
        ;
    for (p = 1; p <= sqrt(k * 1.0); p++) {
        if (k % p == 0) {
            if (k / p - p < minn) {
                minn = k / p - p;
                n = p;
            }
        }
    }
    m = k / n;

    for (i = 0; i < k; i++) {
        if (scanf("%d", &tmp))
            s.push_back(tmp);
    }

    sort(s.begin(), s.end(), cmp);

    i = 1, j = 1, k = 0, N = s.size();
    while (k < N) {
        while (j <= n && !arr[i][j])
            arr[i][j++] = s[k++];
        i++, j--;
        while (i <= m && !arr[i][j])
            arr[i++][j] = s[k++];
        i--, j--;
        while (j >= 1 && !arr[i][j])
            arr[i][j--] = s[k++];
        i--, j++;
        while (i >= 1 && !arr[i][j])
            arr[i--][j] = s[k++];
        i++, j++;
    }

    for (i = 1; i <= m; i++) {
        printf("%d", arr[i][1]);
        for (j = 2; j <= n; j++) {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// The notebook version, which is faster.
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 10010;

int matrix[maxn][maxn], A[maxn];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int N;
    if (scanf("%d", &N))
        ;
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &A[i]))
            ;
    }
    if (N == 1) {
        printf("%d", A[0]);
        return 0;
    }
    sort(A, A + N, cmp);
    int m = (int)ceil(sqrt(1.0 * N));
    while (N % m != 0) {
        m++;
    }

    int n = N / m, i = 1, j = 1, now = 0;
    int U = 1, D = m, L = 1, R = n;
    while (now < N) {
        while (now < N && j < R) {
            matrix[i][j] = A[now++];
            j++;
        }
        while (now < N && i < D) {
            matrix[i][j] = A[now++];
            i++;
        }
        while (now < N && j > L) {
            matrix[i][j] = A[now++];
            j--;
        }
        while (now < N && i > U) {
            matrix[i][j] = A[now++];
            i--;
        }
        U++, D--, L++, R--;
        i++, j++;
        if (now == N - 1) {
            matrix[i][j] = A[now++];
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", matrix[i][j]);
            if (j < n)
                printf(" ");
            else
                printf("\n");
        }
    }
    return 0;
}
