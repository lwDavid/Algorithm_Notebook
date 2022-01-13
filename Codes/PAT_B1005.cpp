#include <stdio.h>
int K = 0, num = 0, tag[3971] = {0}, exist[101] = {0}, count = 0;
void Callatz(int k) {
    while (k != 1) {
        tag[k]++;
        if (k % 2 == 0)
            k /= 2;
        else
            k = (3 * k + 1) / 2;
    }
    return;
}
int main() {
    if (scanf("%d", &K))
        for (int i = 0; i < K; i++)
            if (scanf("%d", &num)) {
                exist[num]++;
                Callatz(num);
            }
    for (int i = 2; i < 101; i++)
        if (tag[i] == 1 && exist[i])
            count++;
    for (int i = 100; i > 1; i--)
        if (tag[i] == 1 && exist[i]) {
            printf("%d", i);
            count--;
            if (count != 0)
                printf(" ");
        }
    printf("\n");
    return 0;
}
