// 오등큰수  // stack
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
  vector<int> cnt(1000001); // save the number of num
  vector<int> ans(N);
  int val;
  for (int i = 0; i < N; i++) {
    cin >> val;
    arr.push_back(val);
    cnt[val]++;
  }
  for (int i = N - 1; i >= 0; i--) { 
    int current = arr[i];
    while (!st.empty() && cnt[st.top()] <= cnt[current]) {
      st.pop(); 
    }    
    if (st.empty()) {
      ans[i] = -1;
      st.push(current);
    }
    else { // not empty  // cnt[st.top()] > cnt[current]
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