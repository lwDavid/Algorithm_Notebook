#include <stdio.h>
int main() {
    int N, pos[100000], t, count = 0, left = 0, k = 1;
    if (scanf("%d", &N)) {
        left = N - 1;
        for (int i = 0; i < N; i++)
            if (scanf("%d", &t)) {
                pos[t] = i;
                if (t == i && i != 0)
                    left--;
            }
    }
    while (left) {
        if (pos[0] == 0) {
            while (k < N) {
                if (pos[k] != k) {
                    pos[0] = pos[k];
                    pos[k] = 0;
                    count++;
                    break;
                }
                k++;
            }
        }
        while (pos[0]) {
            int temp = pos[0];
            pos[0] = pos[pos[0]];
            pos[temp] = temp;
            count++;
            left--;
        }
    }
    printf("%d\n", count);
    return 0;
}
