#include <cstdio>
#include <set>
using namespace std;
set<int> st[51];
void compare(int x, int y) {
    int totalNum = st[y].size(), sameNum = 0;
    for (set<int>::iterator it = st[x].begin(); it != st[x].end(); it++)
        if (st[y].find(*it) != st[y].end())
            sameNum++;
        else
            totalNum++;
    printf("%.1lf%%\n", sameNum * 100.0 / totalNum);
}
int main() {
    int n, k, q, v, st1, st2;
    if (scanf("%d", &n))
        for (int i = 1; i <= n; i++)
            if (scanf("%d", &k))
                for (int j = 0; j < k; j++)
                    if (scanf("%d", &v))
                        st[i].insert(v);
    if (scanf("%d", &q))
        for (int i = 0; i < q; i++)
            if (scanf("%d%d", &st1, &st2))
                compare(st1, st2);
    return 0;
}

// My initial version.
// #include <cstdio>
// #include <set>
// #include <vector>
// using namespace std;
// vector<set<int> > list;
// double similarity(int set1, int set2) {
//     set<int> temp;
//     for (set<int>::iterator it = list[set1 - 1].begin();
//          it != list[set1 - 1].end(); it++)
//         temp.insert(*it);
//     for (set<int>::iterator it = list[set2 - 1].begin();
//          it != list[set2 - 1].end(); it++)
//         temp.insert(*it);
//     return (list[set1 - 1].size() + list[set2 - 1].size() - temp.size()) * 1.0 /
//            temp.size() * 100.0;
// }
// int main() {
//     int sets, elems, elem, queries, qset1, qset2;
//     if (scanf("%d", &sets))
//         while (sets--) {
//             set<int> temp;
//             if (scanf("%d", &elems))
//                 while (elems--)
//                     if (scanf("%d", &elem))
//                         temp.insert(elem);
//             list.push_back(temp);
//         }
//     if (scanf("%d", &queries))
//         while (queries--)
//             if (scanf("%d %d", &qset1, &qset2))
//                 printf("%.1lf%%\n", similarity(qset1, qset2));
//     return 0;
// }
