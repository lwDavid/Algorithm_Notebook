// My version with better time and space complexity.
#include <iostream>
#include <map>
#include <string>
using namespace std;
int id = 0, N, K, pTime, n1, n2, w[2000] = {0}, cnt = 0, h = -1, hw = -1, c = 0;
bool G[2000][2000] = {0}, vis[2000] = {0};
string c1, c2;
map<string, int> Gang, Name2Id;
map<int, string> Id2Name;
int change(string str) {
    if (Name2Id.find(str) != Name2Id.end())
        return Name2Id[str];
    else {
        Name2Id[str] = id;
        Id2Name[id] = str;
        return id++;
    }
}
void DFS(int i) {
    cnt++, c += w[i], vis[i] = 0;
    if (w[i] > hw)
        h = i, hw = w[i];
    for (int j = 0; j < id; j++)
        if (G[i][j] && vis[j])
            DFS(j);
}
int main() {
    if (scanf("%d %d", &N, &K))
        while (N--) {
            cin >> c1 >> c2 >> pTime;
            n1 = change(c1), n2 = change(c2);
            G[n1][n2] = G[n2][n1] = 1;
            vis[n1] = vis[n2] = 1;
            w[n1] += pTime, w[n2] += pTime;
        }
    for (int i = 0; i < id; i++) {
        cnt = 0, h = -1, hw = -1, c = 0;
        if (vis[i]) {
            DFS(i);
            if (cnt > 2 && c > (2 * K))
                Gang[Id2Name[h]] = cnt;
        }
    }
    printf("%d\n", (int)Gang.size());
    if (Gang.size())
        for (map<string, int>::iterator it = Gang.begin(); it != Gang.end();
             it++)
            cout << it->first << ' ' << it->second << endl;
    return 0;
}

// #include <iostream>
// #include <map>
// #include <string>
// using namespace std;
// const int maxn = 2010;
// const int INF = 1000000000;
// map<int, string> intToString;
// map<string, int> stringToInt;
// map<string, int> Gang;
// int G[maxn][maxn] = {0}, weight[maxn] = {0};
// int n, k, numPerson = 0;
// bool vis[maxn] = {false};
// void DFS(int nowVisit, int& head, int& numMember, int& totalValue) {
//     numMember++;
//     vis[nowVisit] = true;
//     if (weight[nowVisit] > weight[head])
//         head = nowVisit;
//     for (int i = 0; i < numPerson; i++) {
//         if (G[nowVisit][i] > 0) {
//             totalValue += G[nowVisit][i];
//             G[nowVisit][i] = G[i][nowVisit] = 0;
//             if (vis[i] == false)
//                 DFS(i, head, numMember, totalValue);
//         }
//     }
// }
// void DFSTravel() {
//     for (int i = 0; i < numPerson; i++)
//         if (vis[i] == false) {
//             int head = i, numMember = 0, totalValue = 0;
//             DFS(i, head, numMember, totalValue);
//             if (numMember > 2 && totalValue > k)
//                 Gang[intToString[head]] = numMember;
//         }
// }
// int change(string str) {
//     if (stringToInt.find(str) != stringToInt.end())
//         return stringToInt[str];
//     else {
//         stringToInt[str] = numPerson;
//         intToString[numPerson] = str;
//         return numPerson++;
//     }
// }
// int main() {
//     int w;
//     string str1, str2;
//     cin >> n >> k;
//     for (int i = 0; i < n; i++) {
//         cin >> str1 >> str2 >> w;
//         int id1 = change(str1);
//         int id2 = change(str2);
//         weight[id1] += w;
//         weight[id2] += w;
//         G[id1][id2] += w;
//         G[id2][id1] += w;
//     }
//     DFSTravel();
//     cout << Gang.size() << endl;
//     map<string, int>::iterator it;
//     for (it = Gang.begin(); it != Gang.end(); it++)
//         cout << it->first << ' ' << it->second << endl;
//     return 0;
// }
