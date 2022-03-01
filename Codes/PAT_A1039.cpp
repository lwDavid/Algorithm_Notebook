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
int main() {
    int N, K, hashTable[26 * 26 * 26 * 10 + 1] = {0};
    vector<vector<int> > list;
    if (scanf("%d %d", &N, &K))
        ;
    while (K--) {
        int courseNum, count, id;
        char inputName[5];
        if (scanf("%d %d", &courseNum, &count))
            ;
        while (count--) {
            if (scanf("%s", inputName))
                ;
            id = getID(inputName);
            if (hashTable[id] == 0) {
                hashTable[id] = list.end() - list.begin() + 1;
                vector<int> temp;
                temp.push_back(courseNum);
                list.push_back(temp);
            } else
                list[hashTable[id] - 1].push_back(courseNum);
        }
    }
    while (N--) {
        int id;
        char query[5];
        if (scanf("%s", query))
            printf("%s ", query);
        id = getID(query);
        if (hashTable[id] == 0)
            printf("0\n");
        else {
            int pos = hashTable[id] - 1;
            printf("%d ", (int)list[pos].size());
            sort(list[pos].begin(), list[pos].end());
            for (vector<int>::iterator it = list[pos].begin();
                 it != list[pos].end(); it++) {
                printf("%d", *it);
                if (it != list[pos].end() - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}

// The reference version with worse time and memory consuming than mine.
// #include <algorithm>
// #include <cstdio>
// #include <cstring>
// #include <vector>
// using namespace std;
// const int N = 40010;
// const int M = 26 * 26 * 26 * 10;
// vector<int> selectCourse[M];
// int getID(char name[]) {
//     int id = 0;
//     for (int i = 0; i < 3; i++)
//         id = id * 26 + (name[i] - 'A');
//     id = id * 10 + (name[3] - '0');
//     return id;
// }
// int main() {
//     char name[5];
//     int n, k;
//     if (scanf("%d %d", &n, &k))
//         ;
//     for (int i = 0; i < k; i++) {
//         int course, x;
//         if (scanf("%d %d", &course, &x))
//             ;
//         for (int j = 0; j < x; j++) {
//             if (scanf("%s", name))
//                 ;
//             int id = getID(name);
//             selectCourse[id].push_back(course);
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         if (scanf("%s", name))
//             ;
//         int id = getID(name);
//         sort(selectCourse[id].begin(), selectCourse[id].end());
//         printf("%s %d", name, (int)selectCourse[id].size());
//         for (int j = 0; j < (int)selectCourse[id].size(); j++)
//             printf(" %d", selectCourse[id][j]);
//         printf("\n");
//     }
//     return 0;
// }
