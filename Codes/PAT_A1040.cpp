// O(n^2) DP method.
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1001;

int main() {
    char str_[maxn];
    int dp[maxn][maxn] = {0};
    int len = 0, ans = 1;

    // Input string
    if (fgets(str_, maxn, stdin)) {
        len = strlen(str_);
    }

    // Initialization
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
        if ((i + 1 <= len - 1) && str_[i] == str_[i + 1]) {
            dp[i][i + 1] = 1;
            ans = 2;
        }
    }

    // DP for longer strings
    for (int L = 3; L <= len; L++) {
        for (int i = 0; i + L - 1 < len; i++) {
            if (str_[i] == str_[i + L - 1] && dp[i + 1][i + L - 2] == 1) {
                dp[i][i + L - 1] = 1;
                ans = L;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
