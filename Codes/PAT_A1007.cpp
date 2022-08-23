// My initial version.
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
