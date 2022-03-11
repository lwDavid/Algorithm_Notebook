#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> rv(1, 0), v(1, 0), temp, ans;
int n, k, p, maxf = 0;
void cmp(int t) {
    if (t > maxf) {
        ans = temp;
        maxf = t;
    } else
        for (int i = 1; i <= k; i++)
            if (temp[i] < ans[i])
                return;
            else if (temp[i] > ans[i]) {
                ans = temp;
                return;
            }
}
void DFS(int index, int facSum, int last, int sum) {
    int up = rv[n - facSum - k + index];
    up = up > last ? last : up;
    for (int i = up; i > 0; i--) {
        temp[index] = i;
        if (maxf != 0 && (k - index + 1) * i + sum < maxf)
            return;
        if (index != k)
            DFS(index + 1, facSum + v[i], i, sum + i);
        else if (facSum + v[i] == n)
            cmp(i + sum);
    }
}
int main() {
    if (scanf("%d%d%d", &n, &k, &p))
        ans.resize(k + 1), temp.resize(k + 1);
    double rp = pow(p, -1);
    for (int i = 1; i <= n - k + 1; i++)
        rv.push_back(pow(i, rp));
    for (int i = 1; i <= rv[n - k + 1]; i++)
        v.push_back(pow(i, p));
    DFS(1, 0, rv[n - k + 1], 0);
    if (ans[1] == 0)
        printf("Impossible\n");
    else {
        printf("%d = %d^%d", n, ans[1], p);
        for (int i = 2; i <= k; i++)
            printf(" + %d^%d", ans[i], p);
        printf("\n");
    }
    return 0;
}
