// 연속합 // prefix sum
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> arr(n + 1);
  int max_val = -1001;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (arr[i - 1] > 0) {
      arr[i] = arr[i - 1] + a;
    }
    else {
      arr[i] = a;
    }
    max_val = max(max_val, arr[i]);
  }
  cout << max_val << "\n";
  
  return 0;
}