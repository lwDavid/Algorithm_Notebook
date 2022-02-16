#include <limits.h>
#include <stdio.h>
int find(int add[], int l, int r, int x) {
    int left = l, right = r, mid;
    while (left < right) {
        mid = (left + right) / 2;
        if (add[mid] > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
int main() {
    int N, M, num, add[100001] = {0}, maxn = INT_MAX, output = 0;
    if (scanf("%d %d", &N, &M))
        for (int i = 1; i <= N; i++)
            if (scanf("%d", &num))
                add[i] += add[i - 1] + num;
    for (int i = 1; i <= N; i++) {
        int j = find(add, i, N + 1, add[i - 1] + M);
        if (add[j - 1] - add[i - 1] == M) {
            maxn = M;
            break;
        } else if (add[j] - add[i - 1] < maxn && j <= N)
            maxn = add[j] - add[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        int j = find(add, i, N + 1, add[i - 1] + maxn);
        if (add[j - 1] - add[i - 1] == maxn) {
            if (output)
                printf("\n");
            printf("%d-%d", i, j - 1);
            output = 1;
        }
    }
    return 0;
}
