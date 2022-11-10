// 조합 // memoization // __uint128_t 사용
#include <bits/stdc++.h>
using namespace std;

__uint128_t table[101][101] = {0,};

__uint128_t binomial(int n, int m) {
	if (table[n][m] != 0) { // if already filled
		return table[n][m];
	}
	else if (m == 0 || n == m) {
		return table[n][m] = 1;
	}
	else if (m == 1) {
		return n;
	}
	else {
		if (m > n / 2) {
			m = n - m;
		}
		return table[n][m] = binomial(n-1, m) + binomial(n-1, m-1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	__uint128_t result = binomial(n, m);
	__uint128_t power = (__uint128_t) pow(10, 15);
	string FB;
	long long quotient = result / power;
	long long remainder = result % power;
	string F = to_string(quotient);
	string B = to_string(remainder);
	if (quotient == 0) {
		FB = B;
	}
	else {
		FB = F + B;
	}
	cout << FB << '\n';

	return 0;
}