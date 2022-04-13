#include <cstdio>
using namespace std;
int father[100], n, m, a, b, tag[100] = {0}, cnt = 0;
int findFather(int x) {
    while (father[x] != x)
        x = father[x];
    return x;
}
void funion(int a, int b) {
    int af = findFather(a), bf = findFather(b);
    if (af != bf)
        father[b] = af;
}
int main() {
    for (int i = 0; i < 100; i++)
        father[i] = i;
    if (scanf("%d %d", &n, &m))
        for (int i = 0; i < m; i++)
            if (scanf("%d %d", &a, &b))
                funion(a, b);
    for (int i = 1; i <= n; i++) {
        if (tag[father[i]] == 0) {
            tag[father[i]] = 1;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
