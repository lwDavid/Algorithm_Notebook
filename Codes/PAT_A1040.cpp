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

const int maxn = 3000;

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

// O(nlogn) string hash method mentioned in the notebook.
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const LL P = 10000019;
const LL MAXN = 200010;

LL powP[MAXN], H1[MAXN], H2[MAXN];

void init() {
    powP[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        powP[i] = (powP[i - 1] * P) % MOD;
    }
}

void calH(LL H[], string& str) {
    H[0] = str[0];
    for (int i = 0; i < (int)str.length(); i++) {
        H[i] = (H[i - 1] * P + str[i]) % MOD;
    }
}

int calSingleSubH(LL H[], int i, int j) {
    if (i == 0)
        return H[j];
    return ((H[j] - H[i - 1] * powP[j - i + 1]) % MOD + MOD) % MOD;
}

int binarySearch(int l, int r, int len, int i, int isEven) {
    while (l < r) {
        int mid = (l + r) / 2;
        int H1L = i - mid + isEven, H1R = i;
        int H2L = len - 1 - (i + mid), H2R = len - 1 - (i + isEven);
        int hashL = calSingleSubH(H1, H1L, H1R);
        int hashR = calSingleSubH(H2, H2L, H2R);
        if (hashL != hashR)
            r = mid;
        else
            l = mid + 1;
    }
    return l - 1;
}

int main() {
    init();
    string str;
    getline(cin, str);
    calH(H1, str);
    reverse(str.begin(), str.end());
    calH(H2, str);
    int ans = 0;
    for (int i = 0; i < (int)str.length(); i++) {
        int maxLen = min(i, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 0);
        ans = max(ans, k * 2 + 1);
    }
    for (int i = 0; i < (int)str.length(); i++) {
        int maxLen = min(i + 1, (int)str.length() - 1 - i) + 1;
        int k = binarySearch(0, maxLen, str.length(), i, 1);
        ans = max(ans, k * 2);
    }
    printf("%d\n", ans);
    return 0;
}
