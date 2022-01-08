#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int cost[24];
struct Call {
    char name[21];
    int month, day, hour, min;
    char state[9];
} list[1000];
bool cmp(Call A, Call B) {
    if (strcmp(A.name, B.name))
        return strcmp(A.name, B.name) < 0;
    else if (A.day != B.day)
        return A.day < B.day;
    else if (A.hour != B.hour)
        return A.hour < B.hour;
    else
        return A.min < B.min;
}
int fee(Call A) {
    int sum = 0, min = A.day * 24 * 60 + A.hour * 60 + A.min;
    int a = min / 1440, b = min % 1440 / 60, c = min % 60;
    for (int i = 0; i < 24; i++) {
        sum += a * 60 * cost[i];
    }
    for (int i = 0; i < b; i++) {
        sum += 60 * cost[i];
    }
    sum += c * cost[b];
    return sum;
}
int main() {
    int N, count = 0, flag = 0;
    double amount = 0.0;
    for (int i = 0; i < 24; i++)
        if (scanf("%d ", &cost[i]))
            ;
    if (scanf("%d", &N))
        ;
    while (N--) {
        if (scanf("%s %d:%d:%d:%d %s", list[count].name, &list[count].month,
                  &list[count].day, &list[count].hour, &list[count].min,
                  list[count].state))
            count++;
    }
    sort(list, list + count, cmp);
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].name, list[i + 1].name)) {
            flag = 0;
            if (amount)
                printf("Total amount: $%.2lf\n", amount);
            amount = 0.0;
        } else if (!strcmp(list[i].state, "on-line") &&
                   !strcmp(list[i + 1].state, "off-line")) {
            if (flag == 0)
                printf("%s %02d\n", list[i].name, list[i].month);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", list[i].day,
                   list[i].hour, list[i].min, list[i + 1].day, list[i + 1].hour,
                   list[i + 1].min,
                   (list[i + 1].day * 24 * 60 + list[i + 1].hour * 60 +
                    list[i + 1].min - list[i].day * 24 * 60 -
                    list[i].hour * 60 - list[i].min),
                   (double)0.01 * (fee(list[i + 1]) - fee(list[i])));
            amount += 0.01 * (double)(fee(list[i + 1]) - fee(list[i]));
            flag++;
        }
    }
    return 0;
}
