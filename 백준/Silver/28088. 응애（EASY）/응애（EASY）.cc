// 응애(HARD)  // 수학  // 조합론
// 응애 : 1, 인사x : 0
// 1번 후 : (a[i - 1] + a[i + 1]) % 2, 2^k번 후 : (a[i - 2^k] + a[i + 2^k]) % 2
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// a^b mod p
ll power(ll a, ll b, ll p) {
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
	ll N, M, K;
	cin >> N >> M >> K;
	vector<ll> a(N);
	ll num;
	for (ll i = 0; i < M; i++) {
		cin >> num;
		a[num] = 1;
	}
	// K와 가장 가까운 K이하 2의 거듭제곱 구하기
	ll v = K;
	while (v & v - 1) {
		v &= v - 1;
	}
	//cout << v << "\n";
	while (K) {
		K -= v;
		vector<ll> b(N); // 임시 배열
		for (ll i = 0; i < N; i++) {
			b[i] = (a[(i - (v % N) + N) % N] + a[(i + v) % N]) % 2;
		}
		for (ll i = 0; i < N; i++) {
			a[i] = b[i];
		}
		while (K < v) { // v <= K일 때 까지 줄이기
			v /= 2;
		}
	}
	ll cnt = 0;
	// K번 이후 상태
	for (ll i = 0; i < N; i++) {
		cnt += a[i];
	}
	cout << cnt << "\n";

	return 0;
}