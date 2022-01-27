#include <algorithm>
#include <cstdio>
using namespace std;
int n, p, a[100000], ans = 1;
int BinarySearch(int i, long long x) {
    if (a[n - 1] <= x)
        return n;
    int l = i + 1, r = n - 1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (a[mid] <= x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int main() {
    if (scanf("%d%d", &n, &p))
        for (int i = 0; i < n; i++)
            if (scanf("%d", &a[i]))
                ;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        int j = BinarySearch(i, (long long)a[i] * p);
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
    return 0;
}
