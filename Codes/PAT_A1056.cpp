#include <cstdio>
#include <queue>
using namespace std;
struct Mouse {
    int weight, rank, index;
} mouse[1000];
int main() {
    queue<Mouse> remain;
    struct Mouse temp;
    int NP, NG, sequence, size, group, maxw = -1, count = 0, i;
    if (scanf("%d %d", &NP, &NG))
        for (int i = 0; i < NP; i++)
            if (scanf("%d", &mouse[i].weight))
                mouse[i].index = i;
    for (int i = 0; i < NP; i++)
        if (scanf("%d", &sequence))
            remain.push(mouse[sequence]);
    while (!remain.empty()) {
        size = remain.size();
        group = size / NG;
        if (size % NG)
            group++;
        if (size == 1) {
            mouse[remain.front().index].rank = 1;
            remain.pop();
            break;
        }
        for (i = 0; i < size; i++) {
            temp = remain.front().weight > maxw ? remain.front() : temp;
            maxw = remain.front().weight > maxw ? remain.front().weight : maxw;
            mouse[remain.front().index].rank = group + 1;
            remain.pop();
            count++;
            if (count == NG || i == size - 1) {
                count = 0, maxw = -1;
                remain.push(temp);
            }
        }
    }
    printf("%d", mouse[0].rank);
    for (int i = 1; i < NP; i++)
        printf(" %d", mouse[i].rank);
    printf("\n");
    return 0;
}
