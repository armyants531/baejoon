// 천국의 계단  // 정수론
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { // a <= b
  ll temp, c;
  while (a != 0) {
    c = b % a;
    b = a;
    a = c;
  }
  return b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll N, A, B;
  cin >> N >> A >> B;
  if (A > B) { // a <= b 가 되도록 순서 변경
    swap(A, B);
  }
  ll GCD = gcd(A, B);
  ll cnt = -1; // i = 0, j = 0 빼야 함
  ll j_max = A / gcd(A, B);
  for (ll j = 0; j < j_max; j++) {
    if (N - j * B > 0) {
      cnt += (N - j * B) / A + 1;
    }
  }
  cout << N - cnt << "\n";
}