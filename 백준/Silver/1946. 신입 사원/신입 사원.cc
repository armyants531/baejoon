// 신입 사원  // greedy
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i].first;
      cin >> A[i].second;
    }
    sort(A.begin(), A.end());
    int cnt = 1;
    int rank_interview = A[0].second;
    for (int i = 1; i < N; i++) {
      if (rank_interview > A[i].second) {
        cnt++;
        rank_interview = A[i].second;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}