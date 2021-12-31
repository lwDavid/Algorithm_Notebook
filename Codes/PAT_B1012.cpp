#include <math.h>
#include <stdio.h>
int main() {
    int n, input, ans[5] = {0}, k = 0, count = 0;
    if (scanf("%d", &n) == 1) {
        while (n--) {
            if (scanf("%d", &input))
                ;
            switch (input % 5) {
                case 0:
                    if (input % 2 == 0)
                        ans[0] += input;
                    break;
                case 1:
                    ans[1] += input * pow(-1, k);
                    k++;
                    break;
                case 2:
                    ans[2]++;
                    break;
                case 3:
                    ans[3] += input;
                    count++;
                    break;
                case 4:
                    if (input > ans[4])
                        ans[4] = input;
                    break;
            }
        }
        if (ans[0] == 0)
            printf("N ");
        else
            printf("%d ", ans[0]);
        if (ans[1] == 0 && k == 0)
            printf("N ");
        else
            printf("%d ", ans[1]);
        if (ans[2] == 0)
            printf("N ");
        else
            printf("%d ", ans[2]);
        if (ans[3] == 0)
            printf("N ");
        else
            printf("%.1f ", ((double)ans[3] / (double)count));
        if (ans[4] == 0)
            printf("N");
        else
            printf("%d", ans[4]);
    }
}
