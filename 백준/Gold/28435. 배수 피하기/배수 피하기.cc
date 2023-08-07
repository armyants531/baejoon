#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
const int p = 1000000007;

// a^b mod p
int power(int a, int b) {
	int ans = 1;
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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> c(K);
	int A;
	for (int i = 0; i < N; i++) {
		cin >> A;
		c[A % K]++;
	}
	int ans = 1;
	for (int i = 1; i < (K + 1) / 2; i++) {
		ans *= ((power(2, c[i]) + power(2, c[K - i]) - 1) % p);
		ans %= p;
	}
	ans *= (c[0] + 1);
	ans %= p;
	if (K % 2 == 0) {
		ans *= (c[K / 2] + 1);
		ans %= p;
	}
	ans -= (N + 1); // 원소가 1개 이하인 부분집합 수 빼기
	cout << (ans + p) % p << "\n";
	
	return 0;
}