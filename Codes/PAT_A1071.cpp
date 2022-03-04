#include <iostream>
#include <map>
#include <string>
using namespace std;
bool check(char c) {
    if (c >= '0' && c <= '9')
        return true;
    if (c >= 'A' && c <= 'Z')
        return true;
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}
int main() {
    map<string, int> count;
    string str;
    getline(cin, str);
    int i = 0;
    while (i < (int)str.length()) {
        string word;
        while (i < (int)str.length() && check(str[i]) == true) {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 32;
            word += str[i];
            i++;
        }
        if (word != "") {
            if (count.find(word) == count.end())
                count[word] = 1;
            else
                count[word]++;
        }
        while (i < (int)str.length() && check(str[i]) == false)
            i++;
    }
    string ans;
    int MAX = 0;
    for (map<string, int>::iterator it = count.begin(); it != count.end(); it++)
        if (it->second > MAX) {
            MAX = it->second;
            ans = it->first;
        }
    cout << ans << " " << MAX << endl;
    return 0;
}

// My initial version.
// #include <iostream>
// #include <map>
// #include <string>
// using namespace std;
// bool isChar(char x) {
//     if ((x >= '0' && x <= '9') || (x >= 'A' && x <= 'Z') ||
//         (x >= 'a' && x <= 'z'))
//         return true;
//     return false;
// }
// void lowwer_cap(string& str) {
//     string::iterator it = str.begin();
//     while (it != str.end()) {
//         if (*it >= 'A' && *it <= 'Z')
//             *it += 'a' - 'A';
//         it++;
//     }
// }
// int main() {
//     int max = 0;
//     string str, ans;
//     map<string, int> count;
//     getline(cin, str);
//     string::iterator it = str.begin();
//     while (it != str.end()) {
//         if (isChar(*it)) {
//             string temp;
//             while (isChar(*it)) {
//                 temp += (*it);
//                 it++;
//             }
//             lowwer_cap(temp);
//             count[temp]++;
//             ans = count[temp] > max ? temp : ans;
//             max = count[temp] > max ? count[temp] : max;
//             if (max == count[temp])
//                 ans = temp < ans ? temp : ans;
//         } else
//             it++;
//     }
//     cout << ans << " " << max << endl;
//     return 0;
// }
