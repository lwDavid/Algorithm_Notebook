// One dimensional DP on 0-1 knapsack problem.
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 10001, maxm = 101;
vector<int> coins;
int N, M, tmp;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    // Input all coins
    if (scanf("%d %d", &N, &M)) {
        for (int i = 0; i < N; i++) {
            if (scanf("%d", &tmp)) {
                coins.push_back(tmp);
            }
        }
    }

    // Sort coins from in decreasing order
    sort(coins.begin(), coins.end(), cmp);
    int n = coins.size(), V = M;

    // Store "whether the n-th coin is used" with choice[n][v]
    // Store coins used in target selection with flag[]
    bool choice[maxn][maxm] = {false}, flag[maxn] = {false};
    int dp[maxm] = {0}, cnt = 0;  // Compress DP into one dimension

    // DP the 0-1 knapsack problem from large to small coins
    for (int i = 1; i <= n; i++) {
        for (int v = V; v >= coins[i - 1]; v--) {
            dp[v] = max(dp[v], dp[v - coins[i - 1]] + coins[i - 1]);
            if (dp[v - coins[i - 1]] + coins[i - 1] >= dp[v]) {
                choice[i][v] = true;
            } else {
                choice[i][v] = false;
            }
        }
    }

    if (dp[M] != M) {
        printf("No Solution\n");  // Cannot pay when dp[M] != M
    } else {
        // Find coins used
        while (n >= 1) {
            if (choice[n][M] == true) {
                flag[n] = true;
                M -= coins[n - 1];
                cnt++;
            } else {
                flag[n] = false;
            }
            n--;
        }
        // Output the result
        for (int i = N; i >= 1; i--) {
            if (flag[i] == true) {
                printf("%d", coins[i - 1]);
                cnt--;
                if (cnt != 0)
                    printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
