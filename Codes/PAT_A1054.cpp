#include <stdio.h>
int main() {
    int M, N, count = 0, ans = -1, T, num;
    if (scanf("%d %d", &M, &N))
        ;
    T = M * N;
    while (T--)
        if (scanf("%d", &num)) {
            if (num == ans)
                count++;
            else if (count > 0)
                count--;
            else {
                ans = num;
                count = 1;
            }
        }
    printf("%d\n", ans);
    return 0;
}

//My version using map.
// #include <cstdio>
// #include <map>
// using namespace std;
// int main() {
//     int M, N, max = 0, half = 0, input, mark;
//     map<int, int> colors;
//     if (scanf("%d %d", &M, &N))
//         half = M * N / 2;
//     while (N--)
//         for (int i = 0; i < M; i++) {
//             if (scanf("%d", &input))
//                 colors[input]++;
//             mark = colors[input] > max ? input : mark;
//             max = colors[input] > max ? colors[input] : max;
//             if (max > half)
//                 break;
//         }
//     printf("%d\n", mark);
//     return 0;
// }

//The reference version.
// #include <cstdio>
// #include <map>
// using namespace std;
// int main() {
//     int n, m, col;
//     if (scanf("%d %d", &n, &m))
//         ;
//     map<int, int> count;
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < m; j++) {
//             if (scanf("%d", &col)) {
//                 if (count.find(col) != count.end())
//                     count[col]++;
//                 else
//                     count[col] = 1;
//             }
//         }
//     int k = 0, MAX = 0;
//     for (map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
//         if (it->second > MAX) {
//             k = it->first;
//             MAX = it->second;
//         }
//     }
//     printf("%d\n", k);
//     return 0;
// }
