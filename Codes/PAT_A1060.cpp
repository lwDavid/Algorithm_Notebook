#include <iostream>
#include <string>
using namespace std;
int findDot(string str) {
    for (int i = 0;; i++) {
        if (str[i] == '.')
            return i;
        if (i == (int)str.length() - 1)
            return str.length();
    }
}
int getK(int dot, int pos) {
    return dot > pos ? dot - pos : dot - pos + 1;
}
void getPrefix(string& str, string& sub, int pos, int N) {
    int i = 0;
    for (; i < N && pos < (int)str.size(); pos++)
        if (str[pos] != '.') {
            sub += str[pos];
            i++;
        }
    for (; i < N; i++)
        sub += '0';
}
void clear(string& str) {
    for (string::iterator it = str.end() - 1; (*it) == '0'; it--)
        str.erase(it);
}
int Zero(string& str) {
    for (string::iterator it = str.begin(); it != str.end(); it++)
        if (*it != '0' && *it != '.')
            return 0;
    return 1;
}
int main() {
    int N, k1 = 0, k2 = 0, j = 0, k = 0, dot1, dot2;
    string A, B, stdA, stdB;
    if (scanf("%d", &N))
        cin >> A >> B;
    dot1 = findDot(A), dot2 = findDot(B);
    while (A[j] == '0' || A[j] == '.')
        j++;
    while (B[k] == '0' || B[k] == '.')
        k++;
    k1 = getK(dot1, j), k2 = getK(dot2, k);
    getPrefix(A, stdA, j, N);
    getPrefix(B, stdB, k, N);
    if (Zero(stdA) && Zero(stdB))
        k1 = k2 = 0;
    if (stdA == stdB && k1 == k2)
        printf("YES 0.%s*10^%d\n", stdA.c_str(), k1);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", stdA.c_str(), k1, stdB.c_str(),
               k2);
    return 0;
}

// The reference version.
// #include <iostream>
// #include <string>
// using namespace std;
// int n;
// string deal(string s, int& e) {
//     int k = 0;
//     while (s.length() > 0 && s[0] == '0')
//         s.erase(s.begin());
//     if (s[0] == '.') {
//         s.erase(s.begin());
//         while (s.length() > 0 && s[0] == '0') {
//             s.erase(s.begin());
//             e--;
//         }
//     } else {
//         while (k < (int)s.length() && s[k] != '.') {
//             k++;
//             e++;
//         }
//         if (k < (int)s.length())
//             s.erase(s.begin() + k);
//     }
//     if (s.length() == 0)
//         e = 0;
//     int num = 0;
//     k = 0;
//     string res;
//     while (num < n) {
//         if (k < (int)s.length())
//             res += s[k++];
//         else
//             res += '0';
//         num++;
//     }
//     return res;
// }
// int main() {
//     string s1, s2, s3, s4;
//     cin >> n >> s1 >> s2;
//     int e1 = 0, e2 = 0;
//     s3 = deal(s1, e1);
//     s4 = deal(s2, e2);
//     if (s3 == s4 && e1 == e2)
//         cout << "YES 0." << s3 << "*10^" << e1 << endl;
//     else
//         cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2
//              << endl;
//     return 0;
// }
