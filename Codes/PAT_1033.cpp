#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int myhash(char t) {
    if (t >= '0' && t <= '9')
        return t - '0';
    else if (t >= 'A' && t <= 'Z')
        return t - 'A' + 10;
    else if (t >= 'a' && t <= 'z')
        return t - 'a' + 10;
    else
        switch (t) {
            case '_':
                return 36;
            case ',':
                return 37;
            case '.':
                return 38;
            case '-':
                return 39;
            case '+':
                return 40;
        }
    return 0;
}
int main() {
    int len1 = 0, len2 = 0, capital = 1;
    bool broken[41] = {false};
    char badkey[41], str[100000], c;
    cin.getline(badkey,sizeof(badkey));
    cin.getline(str,sizeof(str));
    len1=strlen(badkey);
    len2=strlen(str);
    for (int i = 0; i < len1; i++)
        broken[myhash(badkey[i])] = true;
    if (broken[40])
        capital = 0;
    for (int i = 0; i < len2; i++) {
        c = str[i];
        if (!broken[myhash(c)]) {
            if (c >= 'A' && c <= 'Z' && !capital)
                continue;
            else
                printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}

//I think the C codes below are also correct, but it is weird that they can not pass the checkpoint 2.
// #include <cstdio>
// #include <cstring>
// int hash(char t) {
//     if (t >= '0' && t <= '9')
//         return t - '0';
//     else if (t >= 'A' && t <= 'Z')
//         return t - 'A' + 10;
//     else if (t >= 'a' && t <= 'z')
//         return t - 'a' + 10;
//     else
//         switch (t) {
//             case '_':
//                 return 36;
//             case ',':
//                 return 37;
//             case '.':
//                 return 38;
//             case '-':
//                 return 39;
//             case '+':
//                 return 40;
//         }
//     return 0;
// }
// int main() {
//     int len1 = 0, len2 = 0, capital = 1;
//     bool broken[41] = {false};
//     char badkey[41], str[100000], c;
//     if (scanf("%s", badkey))
//         len1 = strlen(badkey);
//     if (scanf("%s", str))
//         len2 = strlen(str);
//     if (!len2) {
//         printf("%s\n", badkey);
//         return 0;
//     }
//     for (int i = 0; i < len1; i++)
//         broken[hash(badkey[i])] = true;
//     if (broken[40])
//         capital = 0;
//     for (int i = 0; i < len2; i++) {
//         c = str[i];
//         if (!broken[hash(c)]) {
//             if (c >= 'A' && c <= 'Z' && !capital)
//                 continue;
//             else
//                 printf("%c", str[i]);
//         }
//     }
//     printf("\n");
//     return 0;
// }
