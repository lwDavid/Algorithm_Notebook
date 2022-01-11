#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Record {
    char ID[8], state[4];
    int hh, mm, ss, time, t;
} list[10000], valid[10000];
bool cmp(Record A, Record B) {
    if (strcmp(A.ID, B.ID))
        return strcmp(A.ID, B.ID) < 0;
    else if (A.hh != B.hh)
        return A.hh < B.hh;
    else if (A.mm != B.mm)
        return A.mm < B.mm;
    else
        return A.ss < B.ss;
}
bool cmp_time(Record A, Record B) {
    if (A.hh != B.hh)
        return A.hh < B.hh;
    else if (A.mm != B.mm)
        return A.mm < B.mm;
    else
        return A.ss < B.ss;
}
int main() {
    int N, K, count = 0, time = 0, qhh, qmm, qss, qtime = 0, cars = 0,
              start = 0;
    if (scanf("%d %d", &N, &K))
        ;
    for (int i = 0; i < N; i++)
        if (scanf("%s %d:%d:%d %s", list[i].ID, &list[i].hh, &list[i].mm,
                  &list[i].ss, list[i].state))
            list[i].t = list[i].hh * 3600 + list[i].mm * 60 + list[i].ss;
    sort(list, list + N, cmp);
    for (int i = 0; i < N; i++)
        if (!strcmp(list[i].ID, list[i + 1].ID)) {
            if (!strcmp(list[i].state, "in") &&
                !strcmp(list[i + 1].state, "out")) {
                time += list[i + 1].t - list[i].t;
                valid[count++] = list[i];
                valid[count++] = list[i + 1];
            }
        } else {
            valid[count - 1].time = time;
            time = 0;
        }
    sort(valid, valid + count, cmp_time);
    while (K--) {
        if (scanf("%d:%d:%d", &qhh, &qmm, &qss))
            qtime = qhh * 3600 + qmm * 60 + qss;
        for (int i = start; i < count; i++) {
            if (valid[i].t <= qtime) {
                if (!strcmp(valid[i].state, "in"))
                    cars++;
                else
                    cars--;
            } else {
                start = i;
                break;
            }
        }
        printf("%d\n", cars);
    }
    sort(valid, valid + count, cmp);
    time = 0;
    for (int i = 1; i < count; i += 2)
        time = (valid[i].time > time) ? valid[i].time : time;
    for (int i = 1; i < count; i += 2)
        if (valid[i].time == time)
            printf("%s ", valid[i].ID);
    printf("%02d:%02d:%02d\n", time / 3600, time % 3600 / 60, time % 60);
    return 0;
}
