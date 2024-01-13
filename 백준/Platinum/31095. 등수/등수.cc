#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long ll;
ll p = 1000000007; // prime
ll MAX = 5000;

ll power(ll a, ll b);
ll bino(ll n, ll x);
ll memo_a(ll N, ll K);
ll memo_b(ll N);

vector<ll> fac(MAX + 2);
vector<ll> inv(MAX + 2); // inv[x]: x! mod p의 inverse
vector<vector<ll>> A(MAX + 1, vector<ll>(MAX + 1));
vector<ll> B(MAX + 1);

// a^b mod p
ll power(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a % p;
	ll pow = power(a, b/2);
	if (b % 2) return (pow * pow % p) * (a % p) % p;
	else return pow * pow % p;
}
// nCx = n! / ((n-x)! * x!)
ll bino(ll n, ll x) {
	return (fac[n] * inv[n - x] % p) * inv[x] % p;
}

ll memo_a(ll N, ll K) {
	if (A[N][K]) return A[N][K];
	if (N < K) return 0; 
	if (K == 1) { // 다른 1등 i명(0<=i<=n-1) 
		for (ll i = 0; i < N; i++) {
			A[N][1] += memo_b(N-i-1) * bino(N-1, i) % p;
			A[N][1] %= p;
		}
		return A[N][1];
	}
	else { // 윗등수 k-1명, 금성 포함 그 이하 n - k + 1명 
		 return A[N][K] = (memo_b(K-1) * bino(N-1, K-1)) % p * memo_a(N-K+1, 1) % p;
	}
}

ll memo_b(ll N) {
	if (B[N]) return B[N];
	for (int i = 1; i <= N; i++) {
		B[N] += memo_a(N, i);
		B[N] %= p;
	}
	return B[N];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	fac[0] = 1;
	for (ll i = 1; i <= MAX; i++) {
		fac[i] = fac[i - 1] * i % p;
	}
	inv[MAX] = power(fac[MAX], p - 2); // a^(p-1) = 1 (mod p), a x a^(p-2) = 1 (mod p), a^(-1) = a^(p-2) (mod p) 
	for (ll i = MAX - 1; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1) % p;
	}
	// init table
	B[0] = 1;
	B[1] = 1;
	while (T--) {
		ll N, K;
		cin >> N >> K;
		if (A[N][K]) {
			cout << A[N][K] << "\n";
		}
		else {
			cout << memo_a(N, K) << "\n";
		}
	} 
	
	return 0;
}