#include <stdio.h>
int main() {
    int num, query, input;
    long long number[1000];
    int spot[1000][2];
    if (scanf("%d", &num))
        ;
    for (int i = 0; i < num; i++) {
        if (scanf("%lld %d %d", &number[i], &spot[i][0], &spot[i][1]))
            ;
    }
    if (scanf("%d", &query))
        ;
    for (int i = 0; i < query; i++) {
        if (scanf("%d", &input))
            ;
        for (int j = 0; j < num; j++) {
            if (spot[j][0] == input)
                printf("%lld %d", number[j], spot[j][1]);
        }
        if (i != query - 1)
            printf("\n");
    }
    return 0;
}
