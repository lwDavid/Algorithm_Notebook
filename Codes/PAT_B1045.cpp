#include <algorithm>
#include <cstdio>
int main() {
    int num[100010], rightMin[100010], temp[100010];
    int leftMax, N, i, j, count = 0;
    if (scanf("%d", &N))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &num[i]))
                ;
    leftMax = 0;
    rightMin[N - 1] = 0x7fffffff;
    i = 0, j = N - 2;
    for (; j >= 0; j--)
        rightMin[j] = std::min(num[j + 1], rightMin[j + 1]);
    for (; i < N; i++) {
        if (i)
            leftMax = std::max(num[i - 1], leftMax);
        if (num[i] < rightMin[i] && num[i] > leftMax)
            temp[count++] = num[i];
    }
    std::sort(temp, temp + count);
    if (!count)
        printf("0\n\n");
    else {
        printf("%d\n%d", count, temp[0]);
        for (int i = 1; i < count; i++)
            printf(" %d", temp[i]);
        printf("\n");
    }
    return 0;
}
