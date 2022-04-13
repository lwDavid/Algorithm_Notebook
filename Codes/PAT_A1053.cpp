#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int N, M, S, weights[100], index = 0;
vector<int> ans;
vector<int> res[100];
struct node {
    int weight;
    vector<int> child;
} Nodes[100];
bool cmp(vector<int> A, vector<int> B) {
    for (int i = 0; i < (int)min(A.size(), B.size()); i++)
        if (A[i] != B[i])
            return A[i] > B[i];
    return A.size() > B.size();
}
void DFS(int root, int S) {
    if (Nodes[root].weight > S ||
        (Nodes[root].weight < S && Nodes[root].child.size() == 0) ||
        (Nodes[root].weight == S && Nodes[root].child.size() > 0))
        return;
    ans.push_back(Nodes[root].weight);
    if (Nodes[root].weight < S) {
        for (int i = 0; i < (int)Nodes[root].child.size(); i++)
            DFS(Nodes[root].child[i], S - Nodes[root].weight);
        ans.pop_back();
    } else {
        res[index++] = ans;
        ans.pop_back();
        return;
    }
}
int main() {
    if (scanf("%d %d %d", &N, &M, &S))
        for (int i = 0; i < N; i++)
            if (scanf("%d", &Nodes[i].weight))
                Nodes[i].child.clear();
    for (int i = 0; i < M; i++) {
        int number, childnum, child;
        if (scanf("%d %d", &number, &childnum))
            for (int j = 0; j < childnum; j++)
                if (scanf("%d", &child))
                    Nodes[number].child.push_back(child);
    }
    DFS(0, S);
    sort(res, res + index, cmp);
    for (int i = 0; i < index; i++) {
        for (int j = 0; j < (int)res[i].size(); j++) {
            printf("%d", res[i][j]);
            if (j + 1 != (int)res[i].size())
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
