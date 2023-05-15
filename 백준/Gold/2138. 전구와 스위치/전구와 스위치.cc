// 전구와 스위치  // greedy
// 첫 스위치를 누른 경우와 누르지 않은 경우로 나누어 생각
// 왼쪽부터 진행하여 현재 상태의 숫자를 바꾸려면 오른쪽 스위치를 눌러야 함
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char trans(char c) {
  if (c == '0') {
    return '1'; 
  }
  else {
    return '0';
  }
}

int check(string s1, string s2, int n) {
  int cnt = 0;
  for (int i = 0; i < n - 2; i++) {
    if (s1[i] != s2[i]) { // 불일치하면
      // 오른쪽 스위치 클릭
      s1[i] = trans(s1[i]);
      s1[i + 1] = trans(s1[i + 1]);
      s1[i + 2] = trans(s1[i + 2]);
      cnt++;
    }
  }
  if (s1[n - 2] != s2[n - 2]) {
    s1[n - 2] = trans(s1[n - 2]);
    s1[n - 1] = trans(s1[n - 1]);
    cnt++;
  }
  if (s1[n - 1] == s2[n - 1]) {
    return cnt;
  }
  else {
    return 200000;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  string s1, s2;
  cin >> s1 >> s2;
  int cnt1 = check(s1, s2, N);
  s1[0] = trans(s1[0]);
  s1[1] = trans(s1[1]);
  int cnt2 = 1 + check(s1, s2, N);
  if (cnt1 == 200000 && cnt2 == 200001) {
    cout << -1 << "\n";
  }
  else {
    cout << min(cnt1, cnt2) << "\n";
  }
  
  return 0;
}