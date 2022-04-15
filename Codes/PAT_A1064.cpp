#include <algorithm>
#include <cstdio>
using namespace std;
int n, arr[1001], in[1001], k = 1;
void creat(int index) {
    if (index > n)
        return;
    creat(2 * index);
    in[index] = arr[k++];
    creat(2 * index + 1);
}
int main() {
    if (scanf("%d", &n))
        for (int i = 1; i <= n; i++)
            if (scanf("%d", &arr[i]))
                ;
    sort(arr + 1, arr + n + 1);
    creat(1);
    for (int i = 1; i < n; i++)
        printf("%d ", in[i]);
    printf("%d\n", in[n]);
    return 0;
}
