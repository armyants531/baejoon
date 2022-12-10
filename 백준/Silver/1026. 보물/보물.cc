// 보물  // greedy
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }
  sort(A.begin(), A.end(), greater<int>());
  sort(B.begin(), B.end());
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i] * B[i];
  }
  cout << sum << "\n";
  
  return 0;
}