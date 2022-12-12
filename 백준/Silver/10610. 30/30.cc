// CESTA  // greedy
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string N;
  cin >> N;
  vector<int> arr;
  bool hasZero = false;
  int sum = 0;
  for (int i = 0; i < N.size(); i++) {
    int num = N[i] - '0';
    if (num == 0) {
      hasZero = true;
    }
    sum += num;
    arr.push_back(num);
  }
  if (hasZero && (sum % 3 == 0)) {
    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < N.size(); i++) {
      cout << arr[i] << "";
    }
    cout << "\n";
  }
  else {
    cout << -1 << "\n";
  }
  
  return 0;
}