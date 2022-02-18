#include <stdio.h>
#include <string.h>
int main() {
    char str[100001];
    int P = 0, A = 0, index = 0, len;
    long T = 0;
    if (scanf("%s", str))
        ;
    len = strlen(str);
    while (index < len) {
        switch (str[index]) {
            case 'P':
                P++;
                break;
            case 'A':
                A += P;
                break;
            case 'T':
                T += A;
                break;
        }
        index++;
    }
    printf("%ld\n", T % 1000000007);
    return 0;
}
