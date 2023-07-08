#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
ll p = 1000000007;
// a^b mod p
ll power(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b % 2 == 1) {
			ans *= a;
			ans %= p;
		}
		b /= 2;
		a = a * a % p;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, a;
	cin >> N >> a;
	ll pow = power(N, a);
	ll pow2 = pow * N;
	pow2 %= p;
	ll pow3 = power(N - 1, a);
	ll right = N * (N - 2) % p;
	ll t = (pow - pow3 + p) % p;
	right *= t;
	right %= p;
	ll sum = pow2 + right;
	sum %= p;
	cout << sum << "\n";

	return 0;
}