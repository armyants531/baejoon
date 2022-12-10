// 잃어버린 괄호  // greedy
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;

  string num = "";
  int result = 0;
  bool minus = false;
  int len = str.size();
  for (int i = 0; i < len; i++) {
    if (minus == true) {
      if (str[i] == '+' || str[i] == '-') {
        result -= stoi(num);
        num = "";
      } 
      else if (i == len - 1) {
        num.push_back(str[i]);
        result -= stoi(num);
      }
      else {
        num.push_back(str[i]);
      }
    } else {
      if (str[i] == '+') {
        result += stoi(num);
        num = "";
      } 
      else if (i == len - 1) {
        num.push_back(str[i]);
        result += stoi(num);
      }
      else if (str[i] == '-') {
        minus = true;
        result += stoi(num);
        num = "";
      } else {
        num.push_back(str[i]);
      }
    }
  }
  cout << result << "\n";

  return 0;
}