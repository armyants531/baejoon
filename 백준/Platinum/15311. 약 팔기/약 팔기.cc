// 약 팔기  // greedy
// 최대 2000개의 약 봉지를 이용하여 1 ~ 1000000까지의 수를 만들면 된다.
// 1000 * 1000 = 1000000
// 1을 999개 나열하면 1~999까지의 모든 수를 만들 수 있다.
// 예시 답안: 1을 1000개 + 1000을 999개 나열 -> K = 1999
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  cout << 1999 << "\n";
  for (int i = 0; i < 1000; i++) {
    cout << 1 << " ";
  }
  for (int i = 0; i < 999; i++) {
    cout << 1001 << " ";
  }
  
  return 0;
}