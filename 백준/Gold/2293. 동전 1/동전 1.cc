// 동전 1  // dp
// table[i] : 가치의 합이 i원이 되게 하는 경우의 수
// x원을 사용해 y원을 만드는 경우의 수 : table[y-x]
#include <bits/stdc++.h>

using namespace std;

int coin[100];
int table[10001];
int n, k;

int dp() {
  table[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = coin[i]; j <= k; j++) {
      table[j] += table[j - coin[i]];
    }     
  }
  return table[k];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) { 
    cin >> coin[i];
  }
  cout << dp() << "\n";

  return 0;
}