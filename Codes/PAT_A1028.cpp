#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Student {
    int ID;
    char name[9];
    int score;
} list[100000];
int C;
bool cmp(Student A, Student B) {
    switch (C) {
        case 1:
            return A.ID < B.ID;
        case 2:
            if (strcmp(A.name, B.name))
                return strcmp(A.name, B.name) < 0;
            else
                return A.ID < B.ID;
        case 3:
            if (A.score != B.score)
                return A.score < B.score;
            else
                return A.ID < B.ID;
        default:
            return A.ID < B.ID;
    }
}
int main() {
    int N, count = 0;
    if (scanf("%d %d", &N, &C))
        ;
    while (N--) {
        if (scanf("%d %s %d", &list[count].ID, list[count].name,
                  &list[count].score))
            count++;
    }
    sort(list, list + count, cmp);
    for (int i = 0; i < count; i++) {
        printf("%06d %s %d", list[i].ID, list[i].name, list[i].score);
        if (i != count - 1)
            printf("\n");
    }
    return 0;
}
