#include <stdio.h>
int main() {
    int num, routes, distance[100005]={0}, input;
    if (scanf("%d", &num))
        ;
    for (int i = 1; i <= num; i++) {
        if (scanf("%d", &input)) {
            distance[i] = (input + distance[i-1]);
        }
    }
    if (scanf("%d", &routes))
        ;
    while (routes--) {
        int res, des, temp, dis1 = 0, dis2 = 0;
        if (scanf("%d %d", &res, &des)) {
            if (res > des) {
                temp = res;
                res = des;
                des = temp;
            }
            dis1 = distance[des - 1] - distance[res - 1];
            dis2 = distance[num] - dis1;
        }
        if (dis1 > dis2)
            printf("%d\n", dis2);
        else
            printf("%d\n", dis1);
    }
    return 0;
}
