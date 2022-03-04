#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, vector<int> > title;
map<string, vector<int> > author;
map<string, vector<int> > keywords;
map<string, vector<int> > publisher;
map<string, vector<int> > year;
void add_keywords(string& str, int ID) {
    string::iterator it = str.begin();
    while (it != str.end()) {
        string temp;
        while (*it != ' ' && it != str.end()) {
            temp += *it;
            it++;
        }
        keywords[temp].push_back(ID);
        if (it != str.end())
            it++;
    }
}
int main() {
    int N, M, ID;
    char qnum;
    if (scanf("%d", &N))
        ;
    while (N--) {
        string titleI, authorI, keywordsI, publisherI, yearI;
        if (scanf("%d\n", &ID))
            ;
        getline(cin, titleI);
        title[titleI].push_back(ID);
        getline(cin, authorI);
        author[authorI].push_back(ID);
        getline(cin, keywordsI);
        add_keywords(keywordsI, ID);
        getline(cin, publisherI);
        publisher[publisherI].push_back(ID);
        getline(cin, yearI);
        year[yearI].push_back(ID);
    }
    if (scanf("%d\n", &M))
        ;
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
                    for (vector<int>::iterator it = publisher[query].begin();
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
