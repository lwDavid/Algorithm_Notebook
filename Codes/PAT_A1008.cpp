#include <stdio.h>
int main() {
    int N, time = 0, now = 0, to = 0;
    if (scanf("%d", &N))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &to)) {
                time += (to > now) ? (to - now) * 6 + 5 : (now - to) * 4 + 5;
                now = to;
            }
    printf("%d\n", time);
    return 0;
}
