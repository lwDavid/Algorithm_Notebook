#include <algorithm>
#include <cstdio>
using namespace std;
struct Mooncake {
    double store;
    double price, sell;
} list[1000];
bool cmp(Mooncake a, Mooncake b) {
    return a.price > b.price;
}
int main() {
    int N;
    double profit = 0.0, D;
    if (scanf("%d %lf", &N, &D))
        for (int i = 0; i < N; i++)
            if (scanf("%lf", &list[i].store))
                ;
    for (int i = 0; i < N; i++)
        if (scanf("%lf", &list[i].sell))
            ;
    for (int i = 0; i < N; i++)
        list[i].price = list[i].sell / list[i].store;
    sort(list, list + N, cmp);
    for (int i = 0; i < N; i++)
        if (D - list[i].store > 0) {
            D -= list[i].store;
            profit += list[i].sell;
        } else {
            profit += D * list[i].price;
            break;
        }
    printf("%.2f\n", profit);
    return 0;
}
