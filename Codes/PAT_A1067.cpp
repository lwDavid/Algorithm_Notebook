#include <stdio.h>
int count = 0;
void swap_0(int arr[], int pos[]) {
    while (arr[0]) {
        arr[pos[0]] = pos[0];
        pos[0] = pos[pos[0]];
        pos[arr[pos[0]]] = arr[pos[0]];
        arr[pos[0]] = 0;
        count++;
    }
}
int main() {
    int N, arr[100000] = {0}, pos[100000] = {0};
    if (scanf("%d", &N))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &arr[i]))
                pos[arr[i]] = i;
    swap_0(arr, pos);
    for (int i = 1; i < N; i++) {
        if (arr[i] != i) {
            arr[0] = arr[i];
            pos[0] = i;
            pos[arr[i]] = 0;
            arr[i] = 0;
            count++;
            swap_0(arr, pos);
        }
    }
    printf("%d\n", count);
    return 0;
}
