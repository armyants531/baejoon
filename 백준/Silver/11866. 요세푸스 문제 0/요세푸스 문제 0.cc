// 요세푸스 문제 0  // stack
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int N, K;
  cin >> N >> K;
  queue<int> que;
  vector<int> ans;
  for (int i = 1; i <= N; i++) {
    que.push(i);
  }
  while (!que.empty()) {
    for (int i = 0; i < K-1; i++) {
      int f1 = que.front();
      que.pop();
      que.push(f1); 
    }
    int f2 = que.front();
    que.pop();
    ans.push_back(f2);
  }
  cout << '<'; 
  for (int i = 0; i < N-1; i++) {
    cout << ans[i] << ", ";
  }
  cout << ans[N-1] << '>' << "\n";
  
  return 0;
}