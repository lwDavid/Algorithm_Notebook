#include <algorithm>
#include <cmath>
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
    int start = 0, i, m;
    double gas = 0.0, cost = 0.0;
    while (start < num) {
        m = -1;
        double min = INFINITY;
        for (i = start + 1; i <= num && (I[i].dis - I[start].dis) <= run; i++) {
            if (I[i].price < min) {
                min = I[i].price;
                m = i;
                if (min < I[start].price)
                    break;
            }
        }
        if (m == -1)
            break;
        double need = (I[m].dis - I[start].dis) / Davg;
        if (min < I[start].price) {
            if (gas < need) {
                cost += (need - gas) * I[start].price;
                gas = 0;
            } else {
                gas -= need;
            }
        } else {
            cost += (V - gas) * I[start].price;
            gas = V - need;
        }
        start = m;
    }
    if (start == num)
        printf("%.2lf\n", cost);
    else
        printf("The maximum travel distance = %.2lf\n", I[start].dis + run);
    return 0;
}
