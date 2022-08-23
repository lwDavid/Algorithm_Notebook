// My initial version.
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
                    c[index++] = t;
    t = -1;
    for (int i = 0; i < index; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (dp[j] + 1 > dp[i] && fav[c[j]] <= fav[c[i]])
                dp[i] = dp[j] + 1;
        t = dp[i] > t ? dp[i] : t;
    }
    printf("%d\n", t);
    return 0;
}
