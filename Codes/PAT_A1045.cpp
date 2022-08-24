// My initial version with a better time consume.
#include <cstdio>
int main() {
    int N, M, L, fav[201], c[10000], dp[10000], t, index = 0;
    bool hashTable[201] = {false};
    if (scanf("%d", &N))
        if (scanf("%d", &M))
            for (int i = 0; i < M; i++)
                if (scanf("%d", &t))
                    hashTable[t] = true, fav[t] = i;
    if (scanf("%d", &L))
        for (int i = 0; i < L; i++)
            if (scanf("%d", &t))
                if (hashTable[t])
                    c[index++] = fav[t];
    t = -1;
    for (int i = 0; i < index; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (dp[j] + 1 > dp[i] && c[j] <= c[i])
                dp[i] = dp[j] + 1;
        t = dp[i] > t ? dp[i] : t;
    }
    printf("%d\n", t);
    return 0;
}

// The notebook version with a better memory consume.
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// using namespace std;
// const int maxc = 210;
// const int maxn = 10010;
// int HashTable[maxc];
// int A[maxn], dp[maxn];
// int main() {
//     int n, m, x;
//     if (scanf("%d%d", &n, &m))
//         memset(HashTable, -1, sizeof(HashTable));
//     for (int i = 0; i < m; i++)
//         if (scanf("%d", &x))
//             HashTable[x] = i;
//     int L, num = 0;
//     if (scanf("%d", &L))
//         for (int i = 0; i < L; i++)
//             if (scanf("%d", &x))
//                 if (HashTable[x] >= 0)
//                     A[num++] = HashTable[x];
//     int ans = -1;
//     for (int i = 0; i < num; i++) {
//         dp[i] = 1;
//         for (int j = 0; j < i; j++)
//             if (A[j] <= A[i] && dp[i] < dp[j] + 1)
//                 dp[i] = dp[j] + 1;
//         ans = max(ans, dp[i]);
//     }
//     printf("%d\n", ans);
//     return 0;
// }

// The notebook version using LCS(Longest Common Subsequence) instead of LIS(Longest Increasing Subsequence), which is much faster but consume more memory.
// #include <algorithm>
// #include <cstdio>
// using namespace std;
// const int maxc = 210;
// const int maxn = 10010;
// int A[maxc], B[maxn], dp[maxc][maxn];
// int main() {
//     int n, m;
//     if (scanf("%d%d", &n, &m))
//         for (int i = 1; i <= m; i++)
//             if (scanf("%d", &A[i]))
//                 ;
//     int L;
//     if (scanf("%d", &L))
//         for (int i = 1; i <= L; i++)
//             if (scanf("%d", &B[i]))
//                 ;
//     for (int i = 0; i <= m; i++)
//         dp[i][0] = 0;
//     for (int j = 0; j <= L; j++)
//         dp[0][j] = 0;
//     for (int i = 1; i <= m; i++)
//         for (int j = 1; j <= L; j++) {
//             int MAX = max(dp[i - 1][j], dp[i][j - 1]);
//             if (A[i] == B[j])
//                 dp[i][j] = MAX + 1;
//             else
//                 dp[i][j] = MAX;
//         }
//     printf("%d\n", dp[m][L]);
//     return 0;
// }
