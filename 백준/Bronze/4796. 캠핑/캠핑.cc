// 캠핑 // greedy
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int L, P, V;
  cin >> L >> P >> V;
  int i = 1;
  while(L != 0) {
    int q = V / P;
    int r = V % P;
    int sum = 0;
    if (r > L) {
      sum = q * L + L;
    }
    else {
      sum = q * L + r;
    }
    cout << "Case " << i << ": " << sum << "\n";
    cin >> L >> P >> V;
    i++;
  }
  
  return 0;
}