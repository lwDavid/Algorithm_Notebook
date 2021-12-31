#include <stdio.h>
int main() {
    int num, score, max = 1;
    int scores[100000] = {0};
    if ((scanf("%d", &num)) == 1) {
        int nums = num;
        int number;
        while (nums--) {
            if ((scanf("%d %d", &number, &score)) == 2) {
                scores[number] += score;
            }
        }
        for (int i = 1; i <= num; i++) {
            if (scores[i] > scores[max])
                max = i;
        }
        printf("%d %d", max, scores[max]);
    }
    return 0;
}
