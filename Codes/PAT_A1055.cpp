#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Rich {
    char name[9];
    int age, worth;
} list[100000];
bool cmp(Rich A, Rich B) {
    if (A.worth != B.worth)
        return A.worth > B.worth;
    else if (A.age != B.age)
        return A.age < B.age;
    else
        return strcmp(A.name, B.name) < 0;
}
int main() {
    int N, K, count = 0, M, Amin, Amax, t = 1, flag;
    if (scanf("%d %d", &N, &K))
        ;
    while (N--) {
        if (scanf("%s %d %d", list[count].name, &list[count].age,
                  &list[count].worth))
            count++;
    }
    sort(list, list + count, cmp);
    while (K--) {
        flag = 0;
        if (scanf("%d %d %d", &M, &Amin, &Amax))
            printf("Case #%d:\n", t++);
        for (int i = 0; i < count; i++) {
            if (list[i].age >= Amin && list[i].age <= Amax && M) {
                printf("%s %d %d\n", list[i].name, list[i].age, list[i].worth);
                flag++, M--;
            }
        }
        if (!flag)
            printf("None\n");
    }
    return 0;
}
