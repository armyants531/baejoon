#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  string s;
  getline(cin, s);
  if (s.empty()) {
    cout << 0;
  }
  else {
    int cnt = 1;
    int len = s.length();
    if (s[0] == ' ') cnt--;
    if (s[len - 1] == ' ') cnt--;
    for (int i = 0; i < len; i++) {
      if (s[i] == ' ') {
        cnt++;
      }
    }
    cout << cnt;
  }

  return 0;
}