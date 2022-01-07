#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct Student {
    char number[14];
    int f_rank, location, l_rank, score;
} list[30000];
bool cmp(Student A, Student B) {
    if (A.score != B.score)
        return A.score > B.score;
    else
        return strcmp(A.number, B.number)<0;
}
int main() {
    int N, K, count = 0, locat = 1, head, end,t;
    if (scanf("%d", &N))
        ;
    while (N--) {
        if (scanf("%d", &K))
            ;
        head = count;
        while (K--) {
            scanf("%s %d", list[count].number, &list[count].score);
            list[count].location = locat;
            count++;
        }
        end = count;
        sort(list+head, list+end, cmp);
        list[head].l_rank = 1,t=1;
        for (int i = head+1; i < end; i++) {
            if (list[i].score == list[i - 1].score)
                list[i].l_rank = list[i - 1].l_rank;
            else
                list[i].l_rank = t + 1;
            t++;
        }
        locat++;
    }
    sort(list, list+count, cmp);
    printf("%d\n", count);
    list[0].f_rank = 1;
    for (int i = 1; i < count; i++) {
        if (list[i].score == list[i - 1].score)
            list[i].f_rank = list[i - 1].f_rank;
        else
            list[i].f_rank = i + 1;
        printf("%s %d %d %d", list[i].number, list[i].f_rank, list[i].location,list[i].l_rank);
        if(i!=count-1) printf("\n");
    }
    return 0;
}
