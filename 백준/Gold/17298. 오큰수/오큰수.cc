// 오큰수  //stack
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int N;
  cin >> N;
  stack<int> st; // decreasing order
  vector<int> arr; 
  vector<int> ans(N);
  int val;
  for (int i = 0; i < N; i++) {
    cin >> val;
    arr.push_back(val);
  }
  for (int i = N - 1; i >= 0; i--) { 
    int current = arr[i];
    while (!st.empty() && st.top() <= current) {
      st.pop(); 
    }    
    if (st.empty()) {
      ans[i] = -1;
      st.push(current);
    }
    else { // not empty  // st.top() > current
      ans[i] = st.top();
      st.push(current);
    }
  }
  
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  
  return 0;
}