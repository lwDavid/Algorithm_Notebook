//(int * int * double) will cause an overflow of int.
//(double * int * int) will not because the data type double is inherited.
#include <stdio.h>
int main() {
    int N;
    double num;
    long double sum = 0.0;
    if (scanf("%d", &N))
        for (int i = N; i > 0; i--)
            if (scanf("%lf", &num))
                sum += num * i * (N - i + 1);
    printf("%.2Lf\n", sum);
    return 0;
}
