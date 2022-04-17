#include <algorithm>
#include <cstdio>
using namespace std;
int n, k, h, father[1001], isRoot[1001] = {0}, course[1001] = {0};
int findFather(int x) {
    int a = x;
    while (x != father[x])
        x = father[x];
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
        father[faA] = faB;
}
void init(int n) {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        isRoot[i] = false;
    }
}
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    if (scanf("%d", &n))
        init(n);
    for (int i = 1; i <= n; i++)
        if (scanf("%d:", &k))
            for (int j = 0; j < k; j++)
                if (scanf("%d", &h)) {
                    if (course[h] == 0)
                        course[h] = i;
                    Union(i, findFather(course[h]));
                }
    for (int i = 1; i <= n; i++)
        isRoot[findFather(i)]++;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (isRoot[i] != 0)
            ans++;
    printf("%d\n", ans);
    sort(isRoot + 1, isRoot + n + 1, cmp);
    for (int i = 1; i <= ans; i++)
        i == ans ? printf("%d\n", isRoot[i]) : printf("%d ", isRoot[i]);
    return 0;
}
