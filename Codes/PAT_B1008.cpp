#include <stdio.h>
int main() {
    int size, step;
    int arr[100];
    if (scanf("%d %d", &size, &step))
        ;
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[(i + step) % size]))
            ;
    }
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size-1)
            printf(" ");
    }
    return 0;
}
