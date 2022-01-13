#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int valid[256] = {0}, len1 = 0,len2=0;
    char str[10001],move[10001];
    cin.getline(str,sizeof(str));
    len1 = strlen(str);
    cin.getline(move,sizeof(move));
    len2=strlen(move);
    for(int i=0;i<len2;i++)
        valid[(int)move[i]]=1;
    for (int i = 0; i < len1; i++)
        if (!valid[(int)str[i]])
            printf("%c", str[i]);
    printf("\n");
    return 0;
}

//I think the C codes below are also correct, but it is weird that they can not pass the checkpoint 1 & 3.
// #include <stdio.h>
// #include <string.h>
// int main() {
//     int valid[256] = {0}, len = 0, k = 0;
//     char str[10001], c;
//     while ((c = getchar()) != '\n')
//         str[k++] = c;
//     len = strlen(str);
//     while ((c = getchar()) != '\n') 
//         valid[(int)c] = 1;
//     for (int i = 0; i < len; i++)
//         if (!valid[(int)str[i]])
//             printf("%c", str[i]);
//     printf("\n");
//     return 0;
// }
