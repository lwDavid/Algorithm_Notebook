#include <stdio.h>
#include <string.h>
char spell[10][6] = {"zero", "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};
void dfs(int n) {
    if (n / 10 == 0) {
        printf("%s", spell[n % 10]);
        return;
    }
    dfs(n / 10);
    printf(" %s", spell[n % 10]);
}
int main() {
    int sum = 0;
    char str[102];
    if (scanf("%s", str))
        ;
    for (int i = 0; i < strlen(str); i++)
        sum += str[i] - '0';
    dfs(sum);
    return 0;
}
