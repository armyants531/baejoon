// 크게 만들기  // greedy  // deque
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, K;
  cin >> N >> K;
  string str;
  cin >> str;
  deque<char> deq;
  deq.push_back(str[0]);
  for (int i = 1; i < N; i++) {
    while (!deq.empty() && K > 0 && str[i] > deq.back()) {
      deq.pop_back();
      K--;
    }
    deq.push_back(str[i]);
  }
  while (K > 0) {
    deq.pop_back();
    K--;
  }
  while (!deq.empty()) {
    cout << deq.front() << "";
    deq.pop_front();
  }
  cout << "\n";
  
  return 0;
}