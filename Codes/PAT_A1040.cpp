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

// O(n) Manacher algorithm
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 2600;

int main() {
    char str_[maxn], news[maxn];
    int len = 0, index = 0, p[maxn] = {0};

    // Initialize the new string
    if (fgets(str_, maxn, stdin)) {
        len = strlen(str_);
        news[index++] = '@';
        for (int i = 0; i < len; i++) {
            news[index++] = '#';
            news[index++] = str_[i];
        }
        news[index] = 0;
        len = strlen(news);
    }

    int right = 0, center = 0, maxlen = 1;

    // Core algorithm
    for (int i = 0; i < len; i++) {
        int mirror = 2 * center - 1;  // Find mirror position
        p[i] = (i >= right)
                   ? 1
                   : min(right - i, p[mirror]);  // Calculate radius of i

        // Expand radius at i
        while (news[i + p[i]] == news[i - p[i]]) {
            p[i]++;
        }

        // Calculate new center and right bound
        if (p[i] + i > right) {
            right = p[i] + i;
            center = i;
        }

        // Record the max symmetric value
        if (maxlen < p[i]) {
            maxlen = p[i];
        }
    }

    printf("%d\n", maxlen - 1);

    return 0;
}
