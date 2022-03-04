//My initial version, which is long and tedious, but runs very fast.
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, vector<int> > title, author, keywords, publisher, year;
int main() {
    int N, M, ID;
    char qnum, c;
    if (scanf("%d", &N))
        while (N--) {
            string titleI, authorI, keywordsI, publisherI, yearI;
            if (scanf("%d\n", &ID))
                ;
            getline(cin, titleI);
            title[titleI].push_back(ID);
            getline(cin, authorI);
            author[authorI].push_back(ID);
            while (cin >> keywordsI) {
                keywords[keywordsI].push_back(ID);
                c = getchar();
                if (c == '\n')
                    break;
            }
            getline(cin, publisherI);
            publisher[publisherI].push_back(ID);
            getline(cin, yearI);
            year[yearI].push_back(ID);
        }
    if (scanf("%d\n", &M))
        while (M--) {
            string query;
            if (scanf("%c: ", &qnum))
                ;
            getline(cin, query);
            printf("%c: %s\n", qnum, query.c_str());
            switch (qnum) {
                case '1':
                    if (title.find(query) == title.end())
                        printf("Not Found\n");
                    else {
                        sort(title[query].begin(), title[query].end());
                        for (vector<int>::iterator it = title[query].begin();
                             it != title[query].end(); it++)
                            printf("%07d\n", *it);
                    }
                    break;
                case '2':
                    if (author.find(query) == author.end())
                        printf("Not Found\n");
                    else {
                        sort(author[query].begin(), author[query].end());
                        for (vector<int>::iterator it = author[query].begin();
                             it != author[query].end(); it++)
                            printf("%07d\n", *it);
                    }
                    break;
                case '3':
                    if (keywords.find(query) == keywords.end())
                        printf("Not Found\n");
                    else {
                        sort(keywords[query].begin(), keywords[query].end());
                        for (vector<int>::iterator it = keywords[query].begin();
                             it != keywords[query].end(); it++)
                            printf("%07d\n", *it);
                    }
                    break;
                case '4':
                    if (publisher.find(query) == publisher.end())
                        printf("Not Found\n");
                    else {
                        sort(publisher[query].begin(), publisher[query].end());
                        for (vector<int>::iterator it =
                                 publisher[query].begin();
                             it != publisher[query].end(); it++)
                            printf("%07d\n", *it);
                    }
                    break;
                case '5':
                    if (year.find(query) == year.end())
                        printf("Not Found\n");
                    else {
                        sort(year[query].begin(), year[query].end());
                        for (vector<int>::iterator it = year[query].begin();
                             it != year[query].end(); it++)
                            printf("%07d\n", *it);
                    }
                    break;
            }
        }
    return 0;
}

//The reference version using set instead of vector, a bit of slower than my initial version.
// #include <cstdio>
// #include <iostream>
// #include <map>
// #include <set>
// #include <string>
// using namespace std;
// map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;
// void query(map<string, set<int> >& mp, string& str) {
//     if (mp.find(str) == mp.end())
//         printf("Not Found\n");
//     else
//         for (set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++)
//             printf("%07d\n", *it);
// }
// int main() {
//     int n, m, id, type;
//     string title, author, key, pub, year;
//     if (scanf("%d", &n))
//         ;
//     for (int i = 0; i < n; i++) {
//         if (scanf("%d", &id))
//             ;
//         char c = getchar();
//         getline(cin, title);
//         mpTitle[title].insert(id);
//         getline(cin, author);
//         mpAuthor[author].insert(id);
//         while (cin >> key) {
//             mpKey[key].insert(id);
//             c = getchar();
//             if (c == '\n')
//                 break;
//         }
//         getline(cin, pub);
//         mpPub[pub].insert(id);
//         getline(cin, year);
//         mpYear[year].insert(id);
//     }
//     string temp;
//     if (scanf("%d", &m))
//         ;
//     for (int i = 0; i < m; i++) {
//         if (scanf("%d: ", &type))
//             ;
//         getline(cin, temp);
//         cout << type << ": " << temp << endl;
//         if (type == 1)
//             query(mpTitle, temp);
//         else if (type == 2)
//             query(mpAuthor, temp);
//         else if (type == 3)
//             query(mpKey, temp);
//         else if (type == 4)
//             query(mpPub, temp);
//         else
//             query(mpYear, temp);
//     }
//     return 0;
// }

// The slowest version. I reduced some repetitive codes by passing map as parameters, which takes a long time.
// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <string>
// #include <vector>
// using namespace std;
// map<string, vector<int> > title, author, keywords, publisher, year;
// void mapfind(string& query, map<string, vector<int> > target) {
//     if (target.find(query) == target.end())
//         printf("Not Found\n");
//     else {
//         sort(target[query].begin(), target[query].end());
//         for (vector<int>::iterator it = target[query].begin();
//              it != target[query].end(); it++)
//             printf("%07d\n", *it);
//     }
// }
// int main() {
//     int N, M, ID;
//     char qnum, c;
//     if (scanf("%d", &N))
//         while (N--) {
//             string titleI, authorI, keywordsI, publisherI, yearI;
//             if (scanf("%d\n", &ID))
//                 ;
//             getline(cin, titleI);
//             title[titleI].push_back(ID);
//             getline(cin, authorI);
//             author[authorI].push_back(ID);
//             while (cin >> keywordsI) {
//                 keywords[keywordsI].push_back(ID);
//                 c = getchar();
//                 if (c == '\n')
//                     break;
//             }
//             getline(cin, publisherI);
//             publisher[publisherI].push_back(ID);
//             getline(cin, yearI);
//             year[yearI].push_back(ID);
//         }
//     if (scanf("%d\n", &M))
//         while (M--) {
//             string query;
//             if (scanf("%c: ", &qnum))
//                 getline(cin, query);
//             printf("%c: %s\n", qnum, query.c_str());
//             switch (qnum) {
//                 case '1':
//                     mapfind(query, title);
//                     break;
//                 case '2':
//                     mapfind(query, author);
//                     break;
//                 case '3':
//                     mapfind(query, keywords);
//                     break;
//                 case '4':
//                     mapfind(query, publisher);
//                     break;
//                 case '5':
//                     mapfind(query, year);
//                     break;
//             }
//         }
//     return 0;
// }
