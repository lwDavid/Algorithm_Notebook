#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Num {
    char num[9];
} nums[10000];
bool cmp(Num a, Num b) {
    int len1 = strlen(a.num), len2 = strlen(b.num), longest = max(len1, len2);
    for (int i = 0, j = 0; i <= longest && j <= longest; i++, j++)
        if (a.num[i % len1] != b.num[j % len2])
            return a.num[i % len1] < b.num[j % len2];
    return 0;
}
int main() {
    int N, i = 0;
    if (scanf("%d", &N))
        for (int i = 0; i < N; i++)
            if (scanf("%s", nums[i].num))
                ;
    sort(nums, nums + N, cmp);
    for (i = 0; i < N; i++) {
        int sum = 0, len = strlen(nums[i].num), base = 1;
        for (int j = len - 1; j >= 0; j--) {
            sum += (nums[i].num[j] - '0') * base;
            base *= 10;
        }
        if (sum) {
            printf("%d", sum);
            break;
        }
    }
    if (i == N)
        printf("0");
    else
        for (i = i + 1; i < N; i++)
            printf("%s", nums[i].num);
    printf("\n");
    return 0;
}
