#define maxn 1000
#include <stdio.h>
struct Student {
    long long id;
    int examSeat;
} testSeat[maxn];
int main() {
    int num, query, seat, examSeat, input;
    long long id;
    if (scanf("%d", &num))
        ;
    for (int i = 0; i < num; i++) {
        if (scanf("%lld %d %d", &id, &seat, &examSeat))
            ;
        testSeat[seat].id = id;
        testSeat[seat].examSeat = examSeat;
    }
    if (scanf("%d", &query))
        ;
    for (int i = 0; i < query; i++) {
        if (scanf("%d", &input))
            ;
        printf("%lld %d", testSeat[input].id, testSeat[input].examSeat);
        if (i != query - 1)
            printf("\n");
    }
    return 0;
}
