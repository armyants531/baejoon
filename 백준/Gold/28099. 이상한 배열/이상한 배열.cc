// 이상한 배열  // tree_set
// 배열을 탐색하며 A[i]가 처음 나왔으면 set에 넣고 마지막으로 나왔으면 set에서 제거한다.
// 만약 A[i]가 set의 가장 작은 원소보다 크면 A는 이상한 배열이 아니다.
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<int> A(N);
        vector<vector<int>> arr(N + 1); // 각 수들이 나온 위치 저장
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            arr[A[i]].push_back(i);
        }
        set<int> s;
        bool isStrange = true;
        for (int i = 0; i < N; i++) {
            if (arr[A[i]][0] == i) { // A[i]가 처음 나왔으면
                s.insert(A[i]);
            }
            set<int>::iterator iter = s.begin(); // set의 가장 작은 원소
            if (*iter < A[i]) {
                isStrange = false;
                break;
            }
            if (arr[A[i]][arr[A[i]].size() - 1] == i) { // A[i]가 마지막으로 나왔으면
                s.erase(A[i]);
            }
        }
        if (isStrange) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }

    return 0;
}