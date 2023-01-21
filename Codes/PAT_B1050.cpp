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
