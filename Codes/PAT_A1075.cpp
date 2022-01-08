#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int K, full[6] = {0};
struct User {
    int id, sum = -1, perfect = 0, submit = 0, compile = 0, rank;
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
    int N, M, problem, score, temp;
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
            list[temp].submit++;
            if (score == full[problem] &&
                list[temp].scores[problem] != full[problem])
                list[temp].perfect++;
            if (score != -1)
                list[temp].compile++;
            if (list[temp].scores[problem] < 0)
                list[temp].scores[problem] = 0;
            list[temp].scores[problem] = (score > list[temp].scores[problem])
                                             ? score
                                             : list[temp].scores[problem];
        }
    }
    for (int i = 1; i <= N; i++) {
        if (list[i].scores[1] >= 0 || list[i].scores[2] >= 0 ||
            list[i].scores[3] >= 0 || list[i].scores[4] >= 0 ||
            list[i].scores[5] >= 0)
            list[i].sum = 0;
        for (int j = 1; j <= K; j++) {
            list[i].sum += list[i].scores[j] >= 0 ? list[i].scores[j] : 0;
        }
    }
    sort(list + 1, list + 1 + N, cmp);
    list[1].rank = 1;
    for (int i = 2; i <= N; i++) {
        if (list[i].sum == list[i - 1].sum)
            list[i].rank = list[i - 1].rank;
        else
            list[i].rank = i;
    }
    for (int i = 1; i <= N; i++) {
        if (!list[i].submit || !list[i].compile)
            continue;
        printf("%d %05d %d", list[i].rank, list[i].id, list[i].sum);
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
