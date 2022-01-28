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

//Another version, contributed by Zhiqin.Q
// #include <algorithm>
// #include <cstdio>
// using namespace std;
// int main() {
//     int nums[100000], N, p, l = 1, r = 1, maxlen, flag;
//     if (scanf("%d%d", &N, &p))
//         for (int i = 0; i < N; i++)
//             if (scanf("%d", &nums[i]))
//                 r = N;
//     sort(nums, nums + N);
//     while (l <= r) {
//         flag = 0;
//         maxlen = (l + r) / 2;
//         for (int i = 0; i + maxlen <= N; i++)
//             if (nums[i + maxlen - 1] <= (long long)nums[i] * p) {
//                 flag = 1;
//                 break;
//             }
//         if (flag)
//             l = maxlen + 1;
//         else
//             r = maxlen - 1;
//     }
//     printf("%d\n", (l + r) / 2);
//     return 0;
// }
