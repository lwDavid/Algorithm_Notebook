#include <algorithm>
#include <cstdio>
int main() {
    int num[100010], rightMin[100010], temp[100010];
    int N, j, count = 0;
    if (scanf("%d", &N))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &num[i]))
                ;
    for (j = N - 2, rightMin[N - 1] = 0x7fffffff; j >= 0; j--)
        rightMin[j] = std::min(num[j + 1], rightMin[j + 1]);
    for (int i = 0, leftMax = 0; i < N; i++) {
        if (i)
            leftMax = std::max(num[i - 1], leftMax);
        if (num[i] < rightMin[i] && num[i] > leftMax)
            temp[count++] = num[i];
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d", temp[i]);
        if (i != count - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
