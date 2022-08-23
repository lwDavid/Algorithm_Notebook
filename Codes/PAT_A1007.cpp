// My initial version with better complexities.
#include <algorithm>
#include <cstdio>
using namespace std;
int main() {
    int K, n[100000], dp[100000], q[100000];
    bool flag = true;
    if (scanf("%d", &K))
        for (int i = 0; i < K; i++)
            if (scanf("%d", &n[i]))
                if (flag == true && n[i] >= 0)
                    flag = false;
    if (flag)
        printf("0 %d %d\n", n[0], n[K - 1]);
    else {
        dp[0] = n[0], q[0] = n[0];
        for (int i = 1; i < K; i++) {
            q[i] = n[i] > dp[i - 1] + n[i] ? n[i] : q[i - 1];
            dp[i] = max(n[i], dp[i - 1] + n[i]);
        }
        int p = K - 1;
        for (int i = K - 2; i >= 0; i--)
            p = dp[i] >= dp[p] ? i : p;
        printf("%d %d %d\n", dp[p], q[p], n[p]);
    }
    return 0;
}

// The notebook version.
// #include <cstdio>
// const int maxn = 10010;
// int a[maxn], dp[maxn];
// int s[maxn] = {0};
// int main() {
//     int n;
//     bool flag = false;
//     if (scanf("%d", &n))
//         for (int i = 0; i < n; i++)
//             if (scanf("%d", &a[i]))
//                 if (a[i] >= 0)
//                     flag = true;
//     if (flag == false) {
//         printf("0 %d %d\n", a[0], a[n - 1]);
//         return 0;
//     }
//     dp[0] = a[0];
//     for (int i = 1; i < n; i++) {
//         if (dp[i - 1] + a[i] > a[i]) {
//             dp[i] = dp[i - 1] + a[i];
//             s[i] = s[i - 1];
//         } else {
//             dp[i] = a[i];
//             s[i] = i;
//         }
//     }
//     int k = 0;
//     for (int i = 1; i < n; i++)
//         if (dp[i] > dp[k])
//             k = i;
//     printf("%d %d %d\n", dp[k], a[s[k]], a[k]);
//     return 0;
// }
