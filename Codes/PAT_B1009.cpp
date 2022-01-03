#include <stdio.h>
#include <string.h>
int main() {
    int count = 0;
    char words[81][81];
    while (scanf("%s", words[count]) != EOF) {
        count++;
    }
    for(int i=count-1;i>=0;i--){
        printf("%s", words[i]);
        if(i!=0) printf(" ");
    }
    return 0;
}
