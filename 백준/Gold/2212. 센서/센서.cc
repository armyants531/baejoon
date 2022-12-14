// 센서  // greedy  // sort
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, K;
  cin >> N >> K;
  vector<int> arr;
  for (int i = 0; i < N; i++) {
    int coord;
    cin >> coord;
    arr.push_back(coord);
  }
  sort(arr.begin(), arr.end());
  vector<int> range;
  for (int i = 1; i < N; i++) {
    int val = arr[i] - arr[i - 1];
    range.push_back(val);
  }
  sort(range.begin(), range.end(), greater<int>());
  int R = arr[N - 1] - arr[0];
  if (N <= K) {
    cout << 0 << "\n";
  }
  else {
    for (int i = 0; i < K - 1; i++) {
      R -= range[i];
    }
    cout << R << "\n";
  }
  
  return 0;
}