// 수열  // sliding window 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, K;
  cin >> N >> K;
  int t;
  vector<int> arr;
  int sum = 0;
  int max_sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> t;
    arr.push_back(t);
    if (i >= K) {
      sum += t;
      sum -= arr[i - K];
      max_sum = max(max_sum, sum);
    }
    else if (i == K - 1) {
      sum += t;
      max_sum = sum;
    }
    else {
      sum += t;   
    }
  }
  cout << max_sum << "\n";

  return 0;
}