#include <cstdio>
#include <stack>
using namespace std;
int main() {
    int M, N, K, get, i, check[1000] = {0};
    if (scanf("%d %d %d", &M, &N, &K))
        while (K--) {
            for (int t = 0; t < N; t++)
                if (scanf("%d", &check[t]))
                    ;
            stack<int> st;
            int num = 1;
            for (i = 0; i < N; i++) {
                get = check[i];
                while (st.empty() || (st.top() != get && (int)st.size() < M))
                    st.push(num++);
                if (st.top() == get) {
                    st.pop();
                    continue;
                } else {
                    printf("NO\n");
                    break;
                }
            }
            if (i == N)
                printf("YES\n");
        }
    return 0;
}
