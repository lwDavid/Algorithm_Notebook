#include <math.h>
#include <stdio.h>
int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}
typedef struct Fraction {
    int up, down;
} Fraction;
Fraction reduction(Fraction result) {
    if (result.down < 0) {
        result.up = -result.up;
        result.down = -result.down;
    }
    if (result.up == 0)
        result.down = 1;
    else {
        int d = gcd(fabs(result.up), fabs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}
void showResult(Fraction r) {
    r = reduction(r);
    if (r.down == 1)
        printf("%d\n", r.up);
    else if (fabs(r.up) > fabs(r.down))
        printf("%d %d/%d\n", r.up / r.down, (int)fabs(r.up) % r.down, r.down);
    else
        printf("%d/%d\n", r.up, r.down);
}
int main() {
    int N;
    Fraction res, F[101];
    res.up = 0, res.down = 1;
    if (scanf("%d", &N))
        for (int i = 0; i < N; i++)
            if (scanf("%d/%d", &F[i].up, &F[i].down))
                ;
    for (int i = 0; i < N; i++)
        res = add(res, F[i]);
    showResult(res);
    return 0;
}
