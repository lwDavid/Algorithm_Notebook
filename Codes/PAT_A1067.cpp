#include <stdio.h>
int main() {
    int N, pos[100000] = {0}, t, count = 0;
    if (scanf("%d", &N))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &t))
                pos[t] = i;
    for (int i = 0; i < N; i++) {
        if (pos[i] != i && i > 0) {
            pos[0] = pos[i];
            pos[i] = 0;
            count++;
        }
        while (pos[0]) {
            int temp = pos[0];
            pos[0] = pos[pos[0]];
            pos[temp] = temp;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
