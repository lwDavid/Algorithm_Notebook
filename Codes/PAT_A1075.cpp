#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int K, full[6] = {0}, N, M, problem, score, temp, urank = 1;
struct User {
    bool compile = false;
    int id, sum = 0, perfect = 0;
    int scores[6] = {-1, -1, -1, -1, -1, -1};
} list[10001];
bool cmp(User A, User B) {
    if (A.sum != B.sum)
        return A.sum > B.sum;
    else if (A.perfect != B.perfect)
        return A.perfect > B.perfect;
    else
        return A.id < B.id;
}
int main() {
    if (scanf("%d %d %d", &N, &K, &M))
        ;
    for (int i = 1; i <= K; i++) {
        if (scanf("%d", &full[i]))
            ;
    }
    for (int i = 1; i <= N; i++)
        list[i].id = i;
    while (M--) {
        if (scanf("%d %d %d", &temp, &problem, &score)) {
            ;
            if (score == full[problem] &&
                list[temp].scores[problem] != full[problem])
                list[temp].perfect++;
            if (score == -1 && list[temp].scores[problem] == -1)
                list[temp].scores[problem] = 0;
            if (score != -1)
                list[temp].compile = true;
            list[temp].scores[problem] = (score > list[temp].scores[problem])
                                             ? score
                                             : list[temp].scores[problem];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (list[i].scores[j] != -1)
                list[i].sum += list[i].scores[j];
        }
    }
    sort(list + 1, list + 1 + N, cmp);
    for (int i = 1; i <= N && list[i].compile; i++) {
        if (i > 1 && list[i].sum != list[i - 1].sum)
            urank = i;
        printf("%d %05d %d", urank, list[i].id, list[i].sum);
        for (int j = 1; j <= K; j++) {
            if (list[i].scores[j] == -1)
                printf(" -");
            else
                printf(" %d", list[i].scores[j]);
        }
        printf("\n");
    }
    return 0;
}
