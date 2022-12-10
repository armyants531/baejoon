// 이항계수와 쿼리  // 분할 정복을 이용한 거듭제곱
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
static ll p = 1000000007;

vector<ll> fact_arr(4000001, 0);

ll factorial(ll n) {
  if (fact_arr[n] != 0) {
    return fact_arr[n];
  }
  if (n == 0) {
    return fact_arr[n] = 1;
  }
  else {
    return fact_arr[n] = n * factorial(n - 1) % p;
  }
}

ll power(ll a, ll b) {
  if (b == 1)
    return a;
  ll pow = power(a, b / 2) % p;
  if (b % 2 == 0)
    return pow * pow % p;
  else {
    return (pow * pow % p) * a % p;
  }
}

ll binomial(ll n , ll k) {
  ll a = factorial(n - k) * factorial(k) % p;
  // (n! mod p) x (((n-k)!k!)^(-1) mod p) mod p = (n! mod p) x (((n-k)!k!)^(p-2) mod p)
  return factorial(n) * power(a, p - 2) % p;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    ll n, k;
    cin >> n >> k;
    cout << binomial(n, k) << "\n";
  }
  return 0;
}