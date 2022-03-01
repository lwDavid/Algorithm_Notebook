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
