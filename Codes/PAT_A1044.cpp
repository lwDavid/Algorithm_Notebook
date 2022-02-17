#include <cstdio>
int sum[100000], n, S, nearS = 100000010;
int upper_bound(int L, int R, int x) {
    int left = L, right = R, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (sum[mid] > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
int main() {
    if (scanf("%d %d", &n, &S))
        sum[0] = 0;
    for (int i = 1; i <= n; i++)
        if (scanf("%d", &sum[i]))
            sum[i] += sum[i - 1];
    for (int i = 1; i <= n; i++) {
        int j = upper_bound(i, n + 1, sum[i - 1] + S);
        if (sum[j - 1] - sum[i - 1] == S) {
            nearS = S;
            break;
        } else if (j <= n && sum[j] - sum[i - 1] < nearS)
            nearS = sum[j] - sum[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        int j = upper_bound(i, n + 1, sum[i - 1] + nearS);
        if (sum[j - 1] - sum[i - 1] == nearS)
            printf("%d-%d\n", i, j - 1);
    }
    return 0;
}
