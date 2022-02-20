#include <stdio.h>
int main() {
    int n, x, a[200], i;
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++)
            if (scanf("%d", &a[i]))
                ;
        if (scanf("%d", &x))
            for (i = 0; i < n; i++)
                if (a[i] == x) {
                    printf("%d\n", i);
                    break;
                }
        if (i == n)
            printf("-1\n");
    }
    return 0;
}
