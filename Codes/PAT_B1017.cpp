#include <stdio.h>
#include <string.h>
struct bign {
    int d[1000];
    int len;
    bign() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};
bign change(char str[]) {
    bign a;
    a.len = strlen(str);
    for (int i = 0; i < a.len; i++)
        a.d[i] = str[a.len - i - 1] - '0';
    return a;
}
bign divide(bign a, int b, int* r) {
    bign c;
    c.len = a.len;
    for (int i = a.len - 1; i >= 0; i--) {
        *r = *r * 10 + a.d[i];
        if (*r < b)
            c.d[i] = 0;
        else {
            c.d[i] = *r / b;
            *r = *r % b;
        }
    }
    while (c.len - 1 >= 1 && c.d[c.len - 1] == 0)
        c.len--;
    return c;
}
void print(bign a) {
    for (int i = a.len - 1; i >= 0; i--)
        printf("%d", a.d[i]);
}
int main() {
    int B, R = 0;
    int* r = &R;
    char str[1001];
    if (scanf("%s %d", str, &B))
        ;
    bign A = change(str);
    bign Q = divide(A, B, r);
    print(Q);
    printf(" %d\n", R);
    return 0;
}
