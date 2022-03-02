#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int getID(char name[]) {
    int id = 0;
    for (int i = 0; i < 3; i++)
        id = id * 26 + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}
void getName(int ID, char name[5]) {
    name[3] = ID % 10 + '0';
    ID /= 10;
    for (int i = 2; i >= 0; i--, ID /= 26)
        name[i] = ID % 26 + 'A';
}
int main() {
    int N, K;
    vector<int> list[2501];
    if (scanf("%d %d", &N, &K))
        ;
    while (N--) {
        int count, id, course = 0;
        char inputName[5];
        if (scanf("%s %d", inputName, &count))
            id = getID(inputName);
        while (count--) {
            if (scanf("%d", &course))
                list[course].push_back(id);
        }
    }
    for (int i = 1; i <= K; i++) {
        printf("%d %d\n", i, (int)list[i].size());
        sort(list[i].begin(), list[i].end());
        for (int j = 0; j < (int)list[i].size(); j++) {
            char outputName[5];
            getName(list[i][j], outputName);
            printf("%s\n", outputName);
        }
    }
    return 0;
}
