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
bign multi2(bign a) {
    bign c;
    int carry = 0;
    for (int i = 0; i < a.len; i++) {
        int temp = a.d[i] * 2 + carry;
        c.d[c.len++] = temp % 10;
        carry = temp / 10;
    }
    while (carry != 0) {
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    return c;
}
void print(bign a) {
    for (int i = a.len - 1; i >= 0; i--)
        printf("%d", a.d[i]);
}
int judge(bign a, bign b) {
    if (a.len != b.len)
        return 0;
    else {
        int count[10] = {0};
        for (int i = 0; i < a.len; i++)
            count[a.d[i]]++;
        for (int i = 0; i < b.len; i++) {
            count[b.d[i]]--;
            if (count[b.d[i]] < 0)
                return 0;
        }
        for (int i = 0; i < 10; i++)
            if (count[i] != 0)
                return 0;
    }
    return 1;
}
int main() {
    char str[21];
    if (scanf("%s", str))
        ;
    bign A = change(str);
    bign Q = multi2(A);
    if (judge(A, Q)) {
        printf("Yes\n");
        print(Q);
    } else {
        printf("No\n");
        print(Q);
    }
    printf("\n");
    return 0;
}
