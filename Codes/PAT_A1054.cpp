#include <iostream>
#include <map>
using namespace std;
int main() {
    int M, N, max = 0;
    string str, mark;
    map<string, int> colors;
    if (scanf("%d %d", &M, &N))
        while (N--)
            for (int i = 0; i < M; i++) {
                cin >> str;
                colors[str]++;
                mark = colors[str] > max ? str : mark;
                max = colors[str] > max ? colors[str] : max;
            }
    cout << mark << endl;
    return 0;
}
