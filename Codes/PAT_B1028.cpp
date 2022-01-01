#include <stdio.h>
struct People {
    char name[6];
    int year, month, day;
} temp, young, old;
int main() {
    int n, count = 0;
    if (scanf("%d", &n))
        ;
    young.year = 1814;
    young.month = 9;
    young.day = 5;
    old.year = 2014;
    old.month = 9;
    old.day = 7;
    for (int i = 0; i < n; i++) {
        if (scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day))
            ;
        if (temp.year < 1814 || (temp.year == 1814 && temp.month < 9) ||
            (temp.year == 1814 && temp.month == 9 && temp.day < 6))
            continue;
        if (temp.year > 2014 || (temp.year == 2014 && temp.month > 9) ||
            (temp.year == 2014 && temp.month == 9 && temp.day > 6))
            continue;
        count++;
        if (temp.year > young.year ||
            (temp.year == young.year && temp.month > young.month) ||
            (temp.year == young.year && temp.month == young.month &&
             temp.day > young.day))
            young = temp;
        if (temp.year < old.year ||
            (temp.year == old.year && temp.month < old.month) ||
            (temp.year == old.year && temp.month == old.month &&
             temp.day < old.day))
            old = temp;
    }
    if (count != 0)
        printf("%d %s %s", count, old.name, young.name);
    else
        printf("0");
    return 0;
}
