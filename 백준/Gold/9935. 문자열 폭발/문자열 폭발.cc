// EKSPLOZIJA  // stack
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str, ex_str;
  cin >> str;
  cin >> ex_str;
  string strings = ""; // use like a stack
  for (int i = 0; i < str.length(); i++) {
    strings += str[i];
    if (strings.back() == ex_str.back()) {
      bool explosion = true;
      if (strings.size() < ex_str.length())
        continue;
      for (int j = 0; j < ex_str.length(); j++) {
        if (strings[strings.size() - 1 - j] !=
            ex_str[ex_str.length() - 1 - j]) {
          explosion = false;
          break;
        }
      }
      if (explosion) {
        for (int j = 0; j < ex_str.length(); j++) {
          strings.pop_back();
        }
      }
    }
  }
  if (strings.empty()) {
    cout << "FRULA" << "\n";
  }
  else {
    cout << strings << "\n";
  }
  return 0;
}