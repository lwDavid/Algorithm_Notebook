#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int quota[100] = {0}, roll[100] = {0}, last[100] = {0};
struct Student {
    int GE, GI, rank, enroll = -1, id;
    double fin;
    int goal[5];
} list[40000];
bool cmp1(Student a, Student b) {
    if (a.fin != b.fin)
        return a.fin > b.fin;
    else
        return a.GE > b.GE;
}
bool cmp2(Student a, Student b) {
    return a.id < b.id;
}
int main() {
    int N, M, K;
    if (scanf("%d %d %d", &N, &M, &K))
        ;
    for (int i = 0; i < M; i++)
        if (scanf("%d ", &quota[i]))
            ;
    for (int i = 0; i < N; i++) {
        if (scanf("%d %d ", &list[i].GE, &list[i].GI)) {
            list[i].fin = (list[i].GE + list[i].GI) / 2.0;
            list[i].id = i;
        }
        for (int j = 0; j < K; j++)
            if (scanf("%d ", &list[i].goal[j]))
                ;
    }
    sort(list, list + N, cmp1);
    for (int i = 0; i < N; i++)
        if (i > 0 && list[i - 1].fin == list[i].fin &&
            list[i - 1].GE == list[i].GE)
            list[i].rank = list[i - 1].rank;
        else
            list[i].rank = i + 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            if (quota[list[i].goal[j]] > 0) {
                list[i].enroll = list[i].goal[j];
                roll[list[i].goal[j]]++;
                quota[list[i].goal[j]]--;
                if (quota[list[i].goal[j]] == 0)
                    last[list[i].goal[j]] = list[i].rank;
                break;
            } else if (list[i].rank == last[list[i].goal[j]]) {
                list[i].enroll = list[i].goal[j];
                roll[list[i].goal[j]]++;
                quota[list[i].goal[j]]--;
                break;
            }
    sort(list, list + N, cmp2);
    for (int i = 0; i < M; i++)
        if (!roll[i])
            printf("\n");
        else {
            for (int j = 0; j < N; j++)
                if (list[j].enroll == i) {
                    printf("%d", j);
                    roll[i]--;
                    if (roll[i])
                        printf(" ");
                }
            printf("\n");
        }
    return 0;
}
