#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Student {
    char name[11], ID[11];
    int grade;
} list[50];
bool cmp(Student a, Student b) {
    return a.grade > b.grade;
}
int main() {
    int N, grade1, grade2, count = 0;
    if (scanf("%d", &N))
        ;
    for (int i = 0; i < N; i++) {
        if (scanf("%s %s %d", list[i].name, list[i].ID, &list[i].grade))
            ;
    }
    sort(list, list + N, cmp);
    if (scanf("%d %d", &grade1, &grade2))
        ;
    for (int i = 0; i < N; i++) {
        if (list[i].grade >= grade1 && list[i].grade <= grade2) {
            printf("%s %s\n", list[i].name, list[i].ID);
            count++;
        }
    }
    if (!count)
        printf("NONE\n");
    return 0;
}
