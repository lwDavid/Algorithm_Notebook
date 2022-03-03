#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<string> i2s = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                      "jly",  "aug", "sep", "oct", "nov", "dec", "tam",
                      "hel",  "maa", "huh", "tou", "kes", "hei", "elo",
                      "syy",  "lok", "mer", "jou"};
map<string, int> s2i = {
    {"tret", 0},  {"jan", 1},   {"feb", 2},   {"mar", 3},   {"apr", 4},
    {"may", 5},   {"jun", 6},   {"jly", 7},   {"aug", 8},   {"sep", 9},
    {"oct", 10},  {"nov", 11},  {"dec", 12},  {"tam", 13},  {"hel", 26},
    {"maa", 39},  {"huh", 52},  {"tou", 65},  {"kes", 78},  {"hei", 91},
    {"elo", 104}, {"syy", 117}, {"lok", 130}, {"mer", 143}, {"jou", 156}};
void E2M(string& str) {
    int num = 0, t = 1, base1 = 0, base0 = 0;
    for (string::iterator it = str.end() - 1; it >= str.begin(); it--, t *= 10)
        num += (*it - '0') * t;
    base0 = num % 13, base1 = num / 13;
    if (!base1)
        cout << i2s[base0] << endl;
    else if (!base0)
        cout << i2s[12 + base1] << endl;
    else
        cout << i2s[12 + base1] << ' ' << i2s[base0] << endl;
}
void M2E(string& str) {
    int num = 0;
    while (str.size()) {
        string temp = str.substr(0, 3);
        num += s2i[temp];
        str.erase(0, 4);
    }
    cout << num << endl;
}
int main() {
    int N;
    string input;
    if (scanf("%d\n", &N))
        ;
    while (N--) {
        getline(cin, input);
        if (input[0] >= '0' && input[0] <= '9')
            E2M(input);
        else
            M2E(input);
    }
    return 0;
}
