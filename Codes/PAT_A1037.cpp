#include <algorithm>
#include <cstdio>
using namespace std;
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int NC, NP, C[100000], P[100000], sum = 0;
    if (scanf("%d", &NC))
        for (int i = 0; i < NC; i++)
            if (scanf("%d", &C[i]))
                ;
    if (scanf("%d", &NP))
        for (int i = 0; i < NP; i++)
            if (scanf("%d", &P[i]))
                ;
    sort(C, C + NC, cmp);
    sort(P, P + NP, cmp);
    for (int i = 0; C[i] > 0 && P[i] > 0; i++)
        sum += C[i] * P[i];
    for (int i = NC - 1, j = NP - 1; C[i] < 0 && P[j] < 0; i--, j--)
        sum += C[i] * P[j];
    printf("%d", sum);
    return 0;
}
