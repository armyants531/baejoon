// 내려가기  // Sliding Window  // DP
// 이전 행과 현재 행의 배열 공간만 사용
#include <bits/stdc++.h>

using namespace std;

struct node {
    int max_v;
    int min_v;
};
vector<vector<node>> table(2, vector<node>(3));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int A, B, C;
    for (int i = 0; i < 3; i++) {
        table[0][i] = { 0, 0 };
    }
    for (int i = 0; i < N; i++) {
        cin >> A >> B >> C;
        // 1행 갱신
        table[1][0] = { A + max(table[0][0].max_v, table[0][1].max_v), A + min(table[0][0].min_v, table[0][1].min_v) };
        table[1][1] = { B + max({table[0][0].max_v, table[0][1].max_v, table[0][2].max_v}), B + min({table[0][0].min_v, table[0][1].min_v, table[0][2].min_v}) };
        table[1][2] = { C + max(table[0][1].max_v, table[0][2].max_v), C + min(table[0][1].min_v, table[0][2].min_v) };
        // 0행 갱신(다음 입력 위해)
        table[0][0] = table[1][0];
        table[0][1] = table[1][1];
        table[0][2] = table[1][2];
    }
    cout << max({ table[0][0].max_v, table[0][1].max_v, table[0][2].max_v }) << " " << min({ table[0][0].min_v, table[0][1].min_v, table[0][2].min_v }) << "\n";
    return 0;
}