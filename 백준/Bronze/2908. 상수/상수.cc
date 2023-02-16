#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 2; i >= 0; i--) {
    if (s1[i] > s2[i]) {
      reverse(s1.begin(), s1.end());
      cout << s1 << "\n";
      break;
    }
    else if (s1[i] < s2[i]) {
      reverse(s2.begin(), s2.end());
      cout << s2 << "\n";
      break;
    }
  }

  return 0;
}