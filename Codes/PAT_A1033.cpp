#include <algorithm>
#include <cstdio>
using namespace std;
struct Station {
    double price = 0.0, dis;
} I[500];
bool cmp(Station a, Station b) {
    return a.dis < b.dis;
}
int main() {
    int num;
    double V, journey, run, Davg;
    if (scanf("%lf %lf %lf %d", &V, &journey, &Davg, &num))
        for (int i = 0; i < num; i++)
            if (scanf("%lf %lf", &I[i].price, &I[i].dis))
                ;
    sort(I, I + num, cmp);
    if (I[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    run = V * Davg;
    I[num].price = 0;
    I[num].dis = journey;
    int start = 0, i;
    double progress = 0.0, gas = 0.0, cost = 0.0;
    while (start < num) {
        if (I[start + 1].dis - I[start].dis > run) {
            printf("The maximum travel distance = %.2f\n", progress + run);
            return 0;
        }
        int min = -1;
        for (i = start + 1; (I[i].dis - I[start].dis) < run && i <= num; i++) {
            if (I[i].price < I[start].price) {
                min = i;
                break;
            }
        }
        if (min == -1) {
            int tmin = start + 1;
            for (i = tmin; (I[i].dis - I[start].dis) < run && i <= num; i++)
                if (I[i].price < I[tmin].price)
                    tmin = i;
            cost += (V - gas) * I[start].price;
            gas = V - (I[tmin].dis - I[start].dis) / Davg;
            progress = I[tmin].dis;
            start = tmin;
        } else {
            progress = I[min].dis;
            if (gas * Davg <= I[min].dis - I[start].dis) {
                cost += ((I[min].dis - I[start].dis) - gas * Davg) / Davg *
                        I[start].price;
                gas = 0;
            } else
                gas -= (I[min].dis - I[start].dis) / Davg;
            start = min;
            continue;
        }
    }
    printf("%.2lf\n", cost);
    return 0;
}
