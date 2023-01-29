// Simulation.
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 10010, maxWindow = 110;

struct Customer {
    int ArriveTime, ServeTime;
} Customers[maxn];

bool cmp(Customer a, Customer b) {
    return a.ArriveTime < b.ArriveTime;
}

int i, N, K, window[maxWindow];
int HH, MM, SS, sTime, ser;
int waited = 0;

int main() {
    if (scanf("%d %d", &N, &K))
        ;

    for (int j = 0; j < K; j++) {  // Initialize all windows
        window[j] = 28800;
    }

    for (i = 0; i < N; i++) {
        if (scanf("%d:%d:%d %d", &HH, &MM, &SS, &ser))
            ;
        sTime = 3600 * HH + 60 * MM + SS;
        Customers[i] = {sTime, ser};
    }

    sort(Customers, Customers + N, cmp);  // Sort by time of arrival

    for (i = 0; i < N && Customers[i].ArriveTime <= 61200; i++) {
        // Find the window to get in
        int getin = 0;
        for (int j = 0; j < K; j++) {
            if (window[j] < window[getin]) {
                getin = j;
            }
        }

        // Get in the found window
        if (window[getin] >
            Customers[i].ArriveTime) {  // The i-th customer is waiting in line
            waited += window[getin] - Customers[i].ArriveTime;
            window[getin] += Customers[i].ServeTime * 60;
        } else {  // Have spare window and do not need to wait
            window[getin] =
                Customers[i].ArriveTime + Customers[i].ServeTime * 60;
        }
    }

    printf("%.1f\n", waited / (i * 60.0));

    return 0;
}
