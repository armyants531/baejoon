// 수리공 항승 // greedy
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, L;
  cin >> N >> L;
  vector<int> arr;
  for (int i = 0; i < N; i++) {
    int coord;
    cin >> coord;
    arr.push_back(coord);
  }
  sort(arr.begin(), arr.end());
  
  int cnt = 1;
  if (N == 1) {
    cout << cnt << "\n";
  }
  else {
    int start = 0;
    for (int i = start + 1; i < N; i++) {
      int len = arr[i] - arr[start] + 1;
      if (len > L) {
        cnt++;
        start = i;
      }
    }
    cout << cnt << "\n";
  }
  
  return 0;
}