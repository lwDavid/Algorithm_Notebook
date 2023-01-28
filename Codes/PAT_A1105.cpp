// Simulation.
#include <limits.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 9973;
const int MAXNUM = 10010;
int arr[maxn][maxn], s[MAXNUM];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int k, tmp, m = 1, n = 1, i, j, p, minn = INT_MAX, N;

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
            s[i] = tmp;
    }

    sort(s, s + k, cmp);

    i = 1, j = 1, N = k, k = 0;
    int U = 1, D = m, L = 1, R = n;
    if (N == 1) {
        printf("%d\n", s[0]);
        return 0;
    }
    while (k < N) {
        while (k < N && j < R) {
            arr[i][j++] = s[k++];
        }
        while (k < N && i < D) {
            arr[i++][j] = s[k++];
        }
        while (k < N && j > L) {
            arr[i][j--] = s[k++];
        }
        while (k < N && i > U) {
            arr[i--][j] = s[k++];
        }
        U++, D--, L++, R--;
        i++, j++;
        if (k == N - 1) {
            arr[i][j] = s[k++];
        }
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
