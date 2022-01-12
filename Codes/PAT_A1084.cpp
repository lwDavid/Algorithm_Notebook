#include <cstdio>
#include <cstring>
int hash(char t) {
    if (t >= '0' && t <= '9')
        return t - '0';
    else if (t >= 'A' && t <= 'Z')
        return t - 'A' + 10;
    else if (t >= 'a' && t <= 'z')
        return t - 'a' + 10;
    else
        return 36;
}
int main() {
    int len1 = 0, len2 = 0;
    bool hashTable[37] = {false};
    char str1[81], str2[81];
    if (scanf("%s", str1))
        len1 = strlen(str1);
    if (scanf("%s", str2))
        len2 = strlen(str2);
    for (int i = 0; i < len2; i++)
        hashTable[hash(str2[i])] = true;
    for (int i = 0; i < len1; i++)
        if (!hashTable[hash(str1[i])]) {
            if (str1[i] >= 'a' && str1[i] <= 'z')
                printf("%c", str1[i] - 'a' + 'A');
            else
                printf("%c", str1[i]);
            hashTable[hash(str1[i])] = true;
        }
    printf("\n");
    return 0;
}
