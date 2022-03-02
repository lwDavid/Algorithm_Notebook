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

// The reference version which performs better in time consuming with small scale inputs than mine.
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <vector>
// using namespace std;
// const int maxn = 40010;
// const int maxc = 2510;
// char name[maxn][5];
// vector<int> course[maxc];
// bool cmp(int a, int b) {
//     return strcmp(name[a], name[b]) < 0;
// }
// int main() {
//     int n, k, c, courseID;
//     if (scanf("%d %d", &n, &k))
//         ;
//     for (int i = 0; i < n; i++) {
//         if (scanf("%s %d", name[i], &c))
//             ;
//         for (int j = 0; j < c; j++)
//             if (scanf("%d", &courseID))
//                 course[courseID].push_back(i);
//     }
//     for (int i = 1; i <= k; i++) {
//         printf("%d %d\n", i, (int)course[i].size());
//         sort(course[i].begin(), course[i].end(), cmp);
//         for (int j = 0; j < (int)course[i].size(); j++)
//             printf("%s\n", name[course[i][j]]);
//     }
//     return 0;
// }
