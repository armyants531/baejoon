// 당근과 채찍  // 수학  // 조합론
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll p = 1000000007;
ll MAX = 2000000;

vector<ll> fac(2000001);
vector<ll> inv(2000001); // inv[x]: x!의 inverse

// a^b mod p
ll power(ll a, ll b, ll p) {
	if (b == 1) {
		return a % p;
	}
	ll pow = power(a, b / 2, p);
	if (b % 2 == 0) {
		return pow * pow % p;
	}
	else {
		return (pow * pow % p) * (a % p) % p;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int Q;
	cin >> Q;
	// 전처리
	ll mul = 1;
	fac[0] = 1;
	for (int i = 1; i <= MAX; i++) {
		fac[i] = (fac[i - 1] * i) % p;
	}
	inv[MAX] = power(fac[MAX], p - 2, p);
	for (int i = MAX - 1; i >= 0; i--) {
		inv[i] = (inv[i + 1] * (i + 1)) % p;
	}
	for (int i = 0; i < Q; i++) {
		ll a, b;
		cin >> a >> b;
		ll ans = (fac[a + b - 1] * inv[a]) % p;
		ans = (ans * inv[b]) % p;
		cout << ans << "\n";
	}
}