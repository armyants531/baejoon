// A와 B  // greedy  // string
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  deque<char> deq;
  string S, T;
  cin >> S;
  cin >> T;
  for (int i = 0; i < T.size(); i++) {
    deq.push_back(T[i]);    
  }
  
  bool isBack = true;
  bool isPossible = true;
  int len = S.length();
  while (deq.size() > len) {
    if (isBack) {
      if (deq.back() == 'B') {
        isBack = !isBack;
      }
      deq.pop_back();
    }
    else {
      if (deq.front() == 'B') {
        isBack = !isBack;
      }
      deq.pop_front();
    }
  }
  if (!isBack) {
    for (int i = 0; i < len; i++) {
      if (deq[i] != S[len - 1 - i]) {
        isPossible = false;
        break;
      }    
    }
  }
  else {
    for (int i = 0; i < len; i++) {
      if (deq[i] != S[i]) {
        isPossible = false;
        break;
      }
    }
  }
  if (isPossible) {
    cout << 1 << "\n";
  }
  else {
    cout << 0 << "\n";
  }
  
  return 0;
}