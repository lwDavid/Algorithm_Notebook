#include <stdio.h>
struct Student {
    char name[11];
    char gender;
    char ID[11];
    short grade;
} temp, f_max, m_min;
int main() {
    int n;
    f_max.grade = -1;
    m_min.grade = 101;
    if (scanf("%d", &n))
        ;
    while (n--) {
        if (scanf("%s %c %s %hd", temp.name, &temp.gender, temp.ID,
                  &temp.grade))
            ;
        if (temp.gender == 'F' && temp.grade > f_max.grade)
            f_max = temp;
        if (temp.gender == 'M' && temp.grade < m_min.grade)
            m_min = temp;
    }
    if (f_max.grade == -1)
        printf("Absent\n");
    else
        printf("%s %s\n", f_max.name, f_max.ID);
    if (m_min.grade == 101)
        printf("Absent\n");
    else
        printf("%s %s\n", m_min.name, m_min.ID);
    if (f_max.grade == -1 || m_min.grade == 101)
        printf("NA");
    else
        printf("%d", f_max.grade - m_min.grade);
    return 0;
}
