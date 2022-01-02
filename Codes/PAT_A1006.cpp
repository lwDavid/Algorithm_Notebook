#include <stdio.h>
struct record {
    char ID[16];
    int signin[3];
    int signout[3];
} temp, unlock, lock;
int later(int a[3], int b[3]) {
    if (a[0] != b[0])
        return a[0] > b[0];
    else if (a[1] != b[1])
        return a[1] > b[1];
    else if (a[2] != b[2])
        return a[2] > b[2];
    else
        return 0;
}
int main() {
    unlock.signin[0] = 24;
    lock.signout[0] = -1;
    int n;
    if (scanf("%d", &n))
        ;
    while (n--) {
        if (scanf("%s %d:%d:%d %d:%d:%d", temp.ID, &temp.signin[0],
                  &temp.signin[1], &temp.signin[2], &temp.signout[0],
                  &temp.signout[1], &temp.signout[2]))
            ;
        if (later(temp.signout, lock.signout))
            lock = temp;
        if (!later(temp.signin, unlock.signin))
            unlock = temp;
    }
    printf("%s %s", unlock.ID, lock.ID);
    return 0;
}
