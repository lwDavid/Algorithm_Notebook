#include <algorithm>
#include <cstdio>
using namespace std;
struct Student {
    int GE, GI, rank, id, fin;
    int goal[5];
} list[40000];
struct Sch {
    int quota;
    int stuNum;
    int id[40000];
    int lastAdmit;
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
    for (int i = 0; i < M; i++) {
        if (scanf("%d ", &sch[i].quota))
            ;
        sch[i].stuNum = 0;
        sch[i].lastAdmit = -1;
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
            int choice = list[i].goal[j];
            int num = sch[choice].stuNum;
            int last = sch[choice].lastAdmit;
            if (num < sch[choice].quota ||
                (last != -1 && list[i].rank == list[last].rank)) {
                sch[choice].id[num] = i;
                sch[choice].lastAdmit = i;
                sch[choice].stuNum++;
                break;
            }
        }
    for (int i = 0; i < M; i++) {
        if (sch[i].stuNum > 0) {
            sort(sch[i].id, sch[i].id + sch[i].stuNum, cmp2);
            for (int j = 0; j < sch[i].stuNum; j++) {
                printf("%d", list[sch[i].id[j]].id);
                if (j < sch[i].stuNum - 1)
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
