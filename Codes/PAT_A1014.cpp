// Simulation.
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 20;
const int MAXK = 1000;
int N, M, K, Q;
int i = 0, j = 0, cnt = 0;
int serTime[MAXK] = {0}, leaveTime[MAXK] = {0}, window[MAXN] = {0};
queue<int> line[MAXN];
int main() {
    if (scanf("%d %d %d %d", &N, &M, &K, &Q))
        ;
    int waitmax = N * M;
    for (i = 0; i < K; i++) {
        if (scanf("%d", &serTime[i]))
            ;
    }
    for (i = 0; i < N; i++) {
        window[i] = 8 * 60;
    }
    for (i = 0; i < N; i++) {
        window[i] += serTime[i];
        leaveTime[i] = window[i];
        line[i].push(i);
        cnt++;
    }
    for (i = N; i < K; i++) {
        int getin = -1, length = __INT_MAX__;
        if (cnt == waitmax) {
            int go = 0, time2leave = __INT_MAX__;
            for (j = 0; j < N; j++) {
                if (leaveTime[line[j].front()] < time2leave) {
                    time2leave = leaveTime[line[j].front()];
                    go = j;
                }
            }
            line[go].pop();
            cnt--;
        }
        for (j = 0; j < N; j++) {
            if (((int)line[j].size() < length) && ((int)line[j].size() < M)) {
                length = (int)line[j].size();
                getin = j;
            }
        }
        if (leaveTime[line[getin].back()] >= 17 * 60 ||
            (leaveTime[line[getin].back()] == -1)) {
            leaveTime[i] = -1;
        } else {
            leaveTime[i] = leaveTime[line[getin].back()] + serTime[i];
        }
        line[getin].push(i);
        cnt++;
    }
    for (i = 0; i < Q; i++) {
        if (scanf("%d", &cnt))
            ;
        if (leaveTime[cnt - 1] == -1) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", leaveTime[cnt - 1] / 60,
                   leaveTime[cnt - 1] % 60);
        }
    }
    return 0;
}
