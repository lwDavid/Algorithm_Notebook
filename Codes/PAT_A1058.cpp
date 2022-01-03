#include <stdio.h>
int main() {
    long long AG, AS, AK, BG, BS, BK;
    if (scanf("%lld.%lld.%lld %lld.%lld.%lld", &AG, &AS, &AK, &BG, &BS, &BK))
        ;
    AK += 17 * 29 * AG + 29 * AS;
    BK += 17 * 29 * BG + 29 * BS;
    AK += BK;
    printf("%lld.%lld.%lld", AK / (17 * 29), AK % (17 * 29) / 29, AK % 29);
    return 0;
}
