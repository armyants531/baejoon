// 배너 걸기  // sliding window
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N >> M;
  int bound = ceil((double)9 * M / 10);
  int start = 1;
  int end = 1;
  vector<int> arr(1000001);
  vector<int> A(N + 1);
  bool can = false;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  while (end <= N) {
    arr[A[end]]++;
    if (end - start > M - 1) {
      arr[A[start]]--;
      start++;
    }
    if (arr[A[end]] >= bound) {
      can = true;
      break;
    }
    // next move
    end++;
  }
  if (can) {
    cout << "YES" << "\n";
  } else {
    cout << "NO" << "\n";
  }
}