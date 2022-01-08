#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int sortn = 0;
struct Student {
    int id;
    int info[4], rank[4];
} list[2000];
bool cmp(Student A, Student B) {
    return A.info[sortn] > B.info[sortn];
}
int main() {
    int N, M, count = 0, search;
    if (scanf("%d %d", &N, &M))
        ;
    while (N--) {
        if (scanf("%d %d %d %d", &list[count].id, &list[count].info[0],
                  &list[count].info[1], &list[count].info[2]))
            list[count].info[3] =
                round((list[count].info[0] + list[count].info[1] +
                       list[count].info[2]) /
                      3.0);
        count++;
    }
    for (int i = 0; i < 4; i++) {
        sort(list, list + count, cmp);
        list[0].rank[sortn] = 1;
        for (int j = 1; j < count; j++) {
            if (list[j].info[sortn] == list[j - 1].info[sortn])
                list[j].rank[sortn] = list[j - 1].rank[sortn];
            else
                list[j].rank[sortn] = j + 1;
        }
        sortn++;
    }
    while (M--) {
        if (scanf("%d", &search))
            ;
        for (int i = 0; i < count; i++) {
            if (list[i].id == search) {
                if (list[i].rank[3] <= list[i].rank[0] &&
                    list[i].rank[3] <= list[i].rank[1] &&
                    list[i].rank[3] <= list[i].rank[2])
                    printf("%d A\n", list[i].rank[3]);
                else if (list[i].rank[0] <= list[i].rank[1] &&
                         list[i].rank[0] <= list[i].rank[2])
                    printf("%d C\n", list[i].rank[0]);
                else if (list[i].rank[1] <= list[i].rank[2])
                    printf("%d M\n", list[i].rank[1]);
                else
                    printf("%d E\n", list[i].rank[2]);
                goto next;
            }
        }
        printf("N/A\n");
    next:;
    }
    return 0;
}
