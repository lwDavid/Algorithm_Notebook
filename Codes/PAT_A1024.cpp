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
bign add(bign a, bign b) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len || i < b.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    if (carry != 0)
        c.d[c.len++] = carry;
    return c;
}
void print(bign a) {
    for (int i = a.len - 1; i >= 0; i--)
        printf("%d", a.d[i]);
}
int palin(bign a) {
    int mid = a.len / 2;
    for (int i = 0; i < mid; i++)
        if (a.d[i] != a.d[a.len - 1 - i])
            return 0;
    return 1;
}
bign op(bign a) {
    bign b;
    b.len = a.len;
    for (int i = 0; i < a.len; i++)
        b.d[i] = a.d[a.len - 1 - i];
    return add(a, b);
}
int main() {
    int K, count = 0;
    char str[12];
    if (scanf("%s %d", str, &K))
        ;
    bign N = change(str);
    while (!palin(N) && count < K) {
        N = op(N);
        count++;
    }
    print(N);
    printf("\n%d\n", count);
    return 0;
}
