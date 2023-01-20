// Divide elements into blocks & maintain the size of blocks.
#include <iostream>
#include <string>
using namespace std;

const int blockSize = 316, blocks = 316;

int op = 0, p = 0, tmp = 0;
int s[100001], table[100001] = {0}, block[blocks] = {0};
string str;

void Pop() {
    if (p != 0) {
        int k = s[--p];
        table[k]--;
        block[k / blockSize]--;
        printf("%d\n", k);
    } else {
        printf("Invalid\n");
    }
    return;
}

void Push(int tmp) {
    s[p++] = tmp;
    table[tmp]++;
    block[tmp / blockSize]++;
    return;
}

void PeekMedian() {
    if (p == 0) {
        printf("Invalid\n");
    } else {
        int rank = p % 2 ? (p + 1) / 2 : p / 2;
        int count = 0;
        for (int i = 0; i <= blocks; i++) {
            if (count + block[i] < rank) {
                count += block[i];
                continue;
            } else {
                for (int j = 0; j < blockSize; j++) {
                    if (count + table[i * blockSize + j] < rank) {
                        count += table[i * blockSize + j];
                        continue;
                    } else {
                        printf("%d\n", i * blockSize + j);
                        return;
                    }
                }
            }
        }
    }
    return;
}

int main() {
    if (scanf("%d", &op))
        ;
    for (; op > 0; op--) {
        cin >> str;
        if (str == "Pop") {
            Pop();
        } else if (str == "Push") {
            cin >> tmp;
            Push(tmp);
        } else if (str == "PeekMedian") {
            PeekMedian();
        }
    }
    return 0;
}
