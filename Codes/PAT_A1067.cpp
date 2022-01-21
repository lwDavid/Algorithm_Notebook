#include <stdio.h>
int count = 0;
void swap_0(int pos[]) {
    while (pos[0]) {
        int temp = pos[0];
        pos[0] = pos[pos[0]];
        pos[temp] = temp;
        count++;
    }
}
int main() {
    int N, pos[100000] = {0}, t;
    if (scanf("%d", &N))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &t))
                pos[t] = i;
    swap_0(pos);
    for (int i = 1; i < N; i++)
        if (pos[i] != i) {
            pos[0] = pos[i];
            pos[i] = 0;
            count++;
            swap_0(pos);
        }
    printf("%d\n", count);
    return 0;
}
