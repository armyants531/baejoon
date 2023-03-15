// 팰린드롬 만들기  // greedy  // string
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  string s;
  cin >> s;
  vector<int> arr(26);
  for (int i = 0; i < s.size(); i++) {
    arr[s[i] - 'A']++;
  }
  string ans = "";
  bool possible = true;
  int mid = -1;
  for (int i = 0; i < 26; i++) {
    if (arr[i] % 2 == 1) {
      arr[i]--;
      if (mid != -1) {
        possible = false;
        break;
      }
      else {
        mid = i;
      }
    }
    if (arr[i] % 2 == 0) {
      int n = arr[i] / 2;
      char c = i + 'A';
      for (int j = 0; j < n; j++) {
        ans += c;
      }
    }
  }
  if (!possible) cout << "I'm Sorry Hansoo" << "\n";
  else {
    cout << ans;
    if (mid != -1) cout << (char)(mid + 'A');
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
  }

  return 0;
}