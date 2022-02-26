#include <stdio.h>
int notpri[10008] = {0}, pri[1230], p = 0;
void init() {
    notpri[0] = notpri[1] = 1;
    for (int i = 2; i < 10008; i++) {
        if (notpri[i] == 0)
            pri[p++] = i;
        for (int j = 0; j < p && i * pri[j] < 10008; j++) {
            notpri[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}
int main() {
    init();
    int MSize, N, num, hashTable[10008] = {0};
    if (scanf("%d %d", &MSize, &N))
        while (notpri[MSize] == 1)
            MSize++;
    while (N--) {
        if (scanf("%d", &num))
            ;
        int pos = num % MSize, i = 1;
        if (hashTable[pos] == 0) {
            printf("%d", pos);
            hashTable[pos] = 1;
        } else {
            while (i <= MSize / 2) {
                if (hashTable[(pos + i * i) % MSize] == 0) {
                    printf("%d", (pos + i * i) % MSize);
                    hashTable[(pos + i * i) % MSize] = 1;
                    break;
                } else
                    i++;
            }
            if (i > MSize / 2)
                printf("-");
        }
        if (N >= 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
