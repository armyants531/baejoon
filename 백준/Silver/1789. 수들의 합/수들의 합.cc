// 수들의 합  // greedy
// if n(n+1)/2 <= S < (n+1)(n+2)/2, ans = n
// n = floor((-1 + sqrt(1 + 8 * S)) / 2)
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double S;
  cin >> S;
  int n = floor((-1 + sqrt(1 + 8 * S)) / 2);
  cout << n << "\n";
  
  return 0;
}