#include <algorithm>
#include <cstdio>
using namespace std;
int n, heapn, init[101], arr[101], heap[101], output = 0, temp = 0;
bool compare(int res[], int arr[]) {
    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (res[i] != arr[i]) {
            flag = false;
            break;
        }
    return flag;
}
void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && heap[j + 1] > heap[j])
            j = j + 1;
        if (heap[j] > heap[i]) {
            swap(heap[j], heap[i]);
            i = j;
            j = i * 2;
        } else
            break;
    }
}
void createHeap() {
    for (int i = n; i >= 1; i--)
        downAdjust(i, n);
}
void heapSort() {
    while (heapn != 1) {
        if (compare(heap, arr))
            output = 1;
        swap(heap[1], heap[heapn--]);
        downAdjust(1, heapn);
        if (output) {
            printf("Heap Sort\n");
            for (int i = 1; i <= n; i++)
                i == n ? printf("%d\n", heap[i]) : printf("%d ", heap[i]);
            return;
        }
    }
}
int main() {
    if (scanf("%d", &n))
        for (int i = 1; i <= n; i++)
            if (scanf("%d", &init[i]))
                heap[i] = init[i];
    for (int i = 1; i <= n; i++)
        if (scanf("%d", &arr[i]))
            ;
    heapn = n;
    createHeap(), heapSort();
    if (output == 0) {
        printf("Insertion Sort\n");
        for (int i = 1, j; i <= n; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                for (j = i; arr[j] > temp; j--)
                    arr[j + 1] = arr[j];
                arr[j + 1] = temp;
                break;
            }
        }
        for (int i = 1; i <= n; i++)
            i == n ? printf("%d\n", arr[i]) : printf("%d ", arr[i]);
    }
    return 0;
}
