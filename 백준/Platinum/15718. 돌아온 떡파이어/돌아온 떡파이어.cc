#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

typedef struct ANSWER {
	int x;
	int y;
} answer;

// n! mod p
ll factorial(ll n, int p) {
	ll val = 1;
	while (n >= 2) {
		val = (val * n) % p;
		n--;
	}
	return val;
}

// a^b mod p
ll power(ll a, int b, int p) {
	if (b == 1)
		return a % p;

	ll pow = power(a, b / 2, p) % p;
	if (b % 2 == 0)
		return pow * pow % p;
	else
		return (pow * pow % p) * (a % p) % p;
}

// nCk mod m
ll binomial(ll n, ll k, int p) {
	if (n < k) {
		return 0; // 중요!
	}
	ll a = factorial(n - k, p) * factorial(k, p) % p;
	return factorial(n, p) * power(a, p - 2, p) % p; // (n! mod p) x (((n-k)!k!)^(-1) mod p) mod p = (n! mod p) x (((n-k)!k!)^(p-2) mod p)
}

// x를 소수 m에 대해 m진 전개
vector<int> expansion(ll x, int m) {
	vector<int> exp;
	while (x > 0) {
		exp.push_back(x % m);
		x /= m;
	}
	return exp;
}

// 뤼카의 정리
ll lucas_thm(ll n, ll k, int m) {
	ll ans = 1;
	vector<int> n_exp = expansion(n, m);
	vector<int> k_exp = expansion(k, m);
	// len(n_exp) >= len(k_exp)
	int len_n = size(n_exp);
	int len_k = size(k_exp);
	for (int i = 0; i < len_n; i++) {
		int K;
		if (i < len_k) {
			K = k_exp[i];
		}
		else {
			K = 0;
		}
		ans = ans * binomial(n_exp[i], K, m) % m;
	}
	return ans;
}

// 확장된 유클리드 호제법으로, am + bn = gcd(m,n) = 1의 해가 되는 정수 a, b를 구한다.
// Extended Euclidean Algorithm
answer EEA(int a, int b) {
	answer xy;
	int r1 = a, r2 = b;
	int s1 = 1, s2 = 0;
	int t1 = 0, t2 = 1;
	int q, r, s, t;
	while (r2 > 0) {
		q = r1 / r2;
		r = r1 - q * r2;
		r1 = r2; r2 = r;

		s = s1 - q * s2;
		s1 = s2; s2 = s;

		t = t1 - q * t2;
		t1 = t2; t2 = t;
	}

	xy.x = s1;
	xy.y = t1;
	return xy;
}

// 중국인의 나머지 정리 (MOD로 나눈 값을 리턴) // x = C1(mod m1), x = C2(mod m2) 
ll CRT(ll C1, ll C2, ll m1, ll m2, int MOD) {
	answer eea;
	eea = EEA(m2, m1);
	ll X = 0;
	// cout << eea.x << " " << eea.y << "\n";
	X += m2 * eea.x * C1;
	X += m1 * eea.y * C2;
	// X가 0보다 작으면
	// cout << X << endl;
	while (X < 0) {
		X += 100007;
	}
	X %= MOD;
	return X;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	long long N, M;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		if (N == 0 && M == 1) {
			cout << 1 << "\n";
		}
		else if (M == 1 || N == 0 || N < M - 1) { // 불가능한 경우 예외처리
			cout << 0 << "\n";
		}
		else {
			ll remainder1 = lucas_thm(N - 1, M - 2, 97);
			ll remainder2 = lucas_thm(N - 1, M - 2, 1031);
			// cout << remainder1 << " " << remainder2 << "\n";
			cout << CRT(remainder1, remainder2, 97, 1031, 100007) << "\n";
		}
	}

	return 0;
}