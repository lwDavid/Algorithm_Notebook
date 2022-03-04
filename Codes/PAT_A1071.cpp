#include <iostream>
#include <map>
#include <string>
using namespace std;
bool isChar(char x) {
    if ((x >= '0' && x <= '9') || (x >= 'A' && x <= 'Z') ||
        (x >= 'a' && x <= 'z'))
        return true;
    return false;
}
void lowwer_cap(string& str) {
    string::iterator it = str.begin();
    while (it != str.end()) {
        if (*it >= 'A' && *it <= 'Z')
            *it += 'a' - 'A';
        it++;
    }
}
int main() {
    int max = 0;
    string str, ans;
    map<string, int> count;
    getline(cin, str);
    string::iterator it = str.begin();
    while (it != str.end()) {
        if (isChar(*it)) {
            string temp;
            while (isChar(*it)) {
                temp += (*it);
                it++;
            }
            lowwer_cap(temp);
            count[temp]++;
            ans = count[temp] > max ? temp : ans;
            max = count[temp] > max ? count[temp] : max;
            if (max == count[temp])
                ans = temp < ans ? temp : ans;
        } else
            it++;
    }
    cout << ans << " " << max << endl;
    return 0;
}
