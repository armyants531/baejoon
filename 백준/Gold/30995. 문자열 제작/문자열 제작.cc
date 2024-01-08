#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
int p = 998244353; // prime
int MAX = 200000;

vector<int> fac(MAX + 1);
vector<int> inv(MAX + 1); // inv[x]: x! mod p의 inverse

// a^b mod p
int power(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a % p;
	int pow = power(a, b/2);
	if (b % 2) return (pow * pow % p) * (a % p) % p;
	else return pow * pow % p;
}

// nCx = n! / ((n-x)! * x!)
int bino(int n, int x) {
	return (fac[n] * inv[n - x] % p) * inv[x] % p;
}

// f(x) = nCx * 25^(n-x)
int func(int n, int x) {
	return bino(n, x) * power(25, n-x) % p;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	fac[0] = 1;
	for (int i = 1; i <= N; i++) {
		fac[i] = fac[i - 1] * i % p;
	}
	inv[N] = power(fac[N], p - 2); // a^(p-1) = 1 (mod p), a x a^(p-2) = 1 (mod p), a^(-1) = a^(p-2) (mod p) 
	for (int i = N - 1; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1) % p;
	}
	// 길이 n 문자열에 A가 x번 등장하는 경우의 수: f(x) = nCx * 25^(n-x)
	// ans = f(M) * f(M) + 2 * (f(M + 1) * f(M) + ... + f(N) * f(M))
	int ans = func(N, M);
	ans *= ans;
	ans %= p;
	for (int i = M + 1; i <= N; i++) {
		ans += (func(N, i) * func(N, M) % p) * 2 % p;
		ans %= p;
	}
	cout << ans << "\n";
	return 0;
}