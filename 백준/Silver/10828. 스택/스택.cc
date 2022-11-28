// 스택
#include <bits/stdc++.h>

using namespace std;

stack<int> st;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int N;
  cin >> N;
  string order;
  for (int i = 0; i < N; i++) {
    cin >> order;
    if (order == "push") {
      int val;
      cin >> val;
      st.push(val);
    }
    else if (order == "pop") {
      if (st.empty()) {
        cout << -1 << "\n";
      }
      else {
        cout << st.top() << "\n";
        st.pop();
      }
    }
    else if (order == "size") {
      cout << st.size() << "\n";
    }
    else if (order == "empty") {
      int ans = (st.empty() ? 1 : 0);
      cout << ans << "\n";
    }
    else if (order == "top") {
      if (st.empty()) {
        cout << -1 << "\n";
      }
      else {
        cout << st.top() << "\n";
      }
    }
  }
  return 0;
}