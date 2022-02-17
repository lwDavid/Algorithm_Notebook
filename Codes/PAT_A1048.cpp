#include <stdio.h>
int main() {
    int N = 0, M = 0, coins[1000] = {0}, coin = 0, i;
    if (scanf("%d %d", &N, &M))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &coin))
                coins[coin]++;
    for (i = 1; i < M; i++)
        if (coins[i] && coins[M - i]) {
            if((i==(M-i))&&coins[i]<2)
                continue;
            printf("%d %d\n", i, M - i);
            return 0;
        }
    printf("No Solution\n");
    return 0;
}

//Another version using binary search.
// #include <algorithm>
// #include <cstdio>
// using namespace std;
// int N, M, coins[100001] = {0};
// int Binary_Search(int L, int R, int x) {
//     int left = L, right = R, mid;
//     while (left < right) {
//         mid = (left + right) / 2;
//         if (coins[mid] > x)
//             right = mid;
//         else
//             left = mid + 1;
//     }
//     return left;
// }
// int main() {
//     if (scanf("%d %d", &N, &M))
//         for (int i = 1; i <= N; i++)
//             if (scanf("%d", &coins[i]))
//                 ;
//     sort(coins + 1, coins + N + 1);
//     if (N > 1)
//         for (int i = 1; i <= N; i++) {
//             int j = Binary_Search(i, N + 1, M - coins[i]);
//             if (coins[i] + coins[j - 1] == M && i != j - 1) {
//                 printf("%d %d\n", coins[i], coins[j - 1]);
//                 return 0;
//             }
//         }
//     printf("No Solution\n");
//     return 0;
// }
