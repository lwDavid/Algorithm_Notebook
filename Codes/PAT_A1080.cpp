#include <algorithm>
#include <cstdio>
using namespace std;
struct Student {
    int GE, GI, rank, id, fin;
    int goal[5];
} list[40000];
struct School {
    int quota, roll, last;
    int id[40000];
} sch[100];
bool cmp1(Student a, Student b) {
    if (a.fin != b.fin)
        return a.fin > b.fin;
    else
        return a.GE > b.GE;
}
bool cmp2(int a, int b) {
    return list[a].id < list[b].id;
}
int main() {
    int N, M, K;
    if (scanf("%d %d %d", &N, &M, &K))
        ;
    for (int i = 0; i < M; i++)
        if (scanf("%d ", &sch[i].quota)) {
            sch[i].roll = sch[i].last = 0;
        }
    for (int i = 0; i < N; i++) {
        if (scanf("%d %d ", &list[i].GE, &list[i].GI)) {
            list[i].fin = list[i].GE + list[i].GI;
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
        for (int j = 0; j < K; j++) {
            int roll = sch[list[i].goal[j]].roll;
            int goal = list[i].goal[j];
            if (sch[goal].quota > 0 || list[i].rank == sch[goal].last) {
                sch[goal].id[roll] = i;
                sch[goal].roll++;
                sch[goal].quota--;
                if (sch[goal].quota == 0)
                    sch[goal].last = list[i].rank;
                break;
            }
        }
    for (int i = 0; i < M; i++) {
        if (sch[i].roll) {
            sort(sch[i].id, sch[i].id + sch[i].roll, cmp2);
            for (int j = 0; j < sch[i].roll; j++) {
                printf("%d", list[sch[i].id[j]].id);
                if (j != sch[i].roll - 1)
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
