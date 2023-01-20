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
        int count = 0, index = 0;
        while (count + block[index] < rank) {
            count += block[index++];
        }
        index *= blockSize;
        while (count + table[index] < rank) {
            count += table[index++];
        }
        printf("%d\n", index);
        return;
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

// Better time complexity as O(log^2(x)) using BIT (Binary Indexed Tree).
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define lowbit(i) ((i) & (-i))
const int MAXN = 100010;
stack<int> s;
int c[MAXN];
void update(int x, int v) {
    for (int i = x; i < MAXN; i += lowbit(i)) {
        c[i] += v;
    }
}
int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}
void PeekMedian() {
    int l = 1, r = MAXN, mid, K = (s.size() + 1) / 2;
    while (l < r) {
        mid = (l + r) / 2;
        if (getSum(mid) >= K)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n", l);
}

int main() {
    int n, x;
    char str[12];
    if (scanf("%d", &n))
        ;
    for (int i = 0; i < n; i++) {
        if (scanf("%s", str))
            ;
        if (strcmp(str, "Push") == 0) {
            if (scanf("%d", &x))
                ;
            s.push(x);
            update(x, 1);
        } else if (strcmp(str, "Pop") == 0) {
            if (s.empty())
                printf("Invalid\n");
            else {
                printf("%d\n", s.top());
                update(s.top(), -1);
                s.pop();
            }
        } else if (strcmp(str, "PeekMedian") == 0) {
            if (s.empty())
                printf("Invalid\n");
            else
                PeekMedian();
        }
    }
    return 0;
}
