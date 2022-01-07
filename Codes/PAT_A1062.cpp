#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Man {
    char id[9];
    int virtue, talent, type;
} list[100000], temp;
bool cmp(Man A, Man B) {
    if (A.type != B.type)
        return A.type > B.type;
    else if ((A.talent + A.virtue) != (B.talent + B.virtue))
        return (A.talent + A.virtue) > (B.talent + B.virtue);
    else if (A.virtue != B.virtue)
        return A.virtue > B.virtue;
    else
        return strcmp(A.id, B.id) < 0;
}
int main() {
    int N, L, H, count = 0;
    if (scanf("%d %d %d", &N, &L, &H))
        ;
    while (N--) {
        if (scanf("%s %d %d", temp.id, &temp.virtue, &temp.talent))
            ;
        if (temp.talent >= L && temp.virtue >= L) {
            list[count] = temp;
            if (temp.talent >= H && temp.virtue >= H)
                list[count].type = 3;
            else if (temp.virtue >= H)
                list[count].type = 2;
            else if (temp.virtue >= temp.talent)
                list[count].type = 1;
            else
                list[count].type = 0;
            count++;
        }
    }
    sort(list, list + count, cmp);
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s %d %d", list[i].id, list[i].virtue, list[i].talent);
        if (i != count - 1)
            printf("\n");
    }
    return 0;
}
