// CESTA  // greedy
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string S;
  cin >> S;
  int num0 = 0;
  int num1 = 0;
  int num;
  if (S[0] == '0') {
    num0++;
    num = 0;
  }
  else {
    num1++;
    num = 1;
  }
  
  for (int i = 1; i < S.size(); i++) {
    if (S[i] != num) {
      num = S[i];
      if (S[i] == '0') {
        num0++;
      }
      else {
        num1++;
      }
    } 
  }
  cout << min(num0, num1) << "\n";
  
  return 0;
}