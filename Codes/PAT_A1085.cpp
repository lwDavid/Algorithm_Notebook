#include <algorithm>
#include <cstdio>
int main() {
    int nums[100000], N, p, i = 0, j = 0, count = 0;
    if (scanf("%d%d", &N, &p))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &nums[i]))
                ;
    std::sort(nums, nums + N);
    while (i < N && j < N) {
        while (j < N && nums[j] <= (long long)nums[i] * p) {
            count = std::max(count, j - i + 1);
            j++;
        }
        i++;
    }
    printf("%d\n", count);
    return 0;
}
