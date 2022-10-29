#include <iostream>
#include <vector>

using namespace std;

long long memo[2001][2001]; // memoization: memo[i][j] = iCj

// nCk mod m
long long binomial(int n, int k, int m) {
	if (memo[n][k] != -1) {
		return memo[n][k];
	}
	else if (n < k) {
		memo[n][k] = 0;
		return memo[n][k];
	}
	else if (n == k || k == 0) {
		memo[n][k] = 1;
		return memo[n][k];
	}
	else {
		memo[n][k] = (binomial(n - 1, k - 1, m) + binomial(n - 1, k, m)) % m;
		return memo[n][k];
	}
}

// x를 소수 m에 대해 m진 전개
vector<int> expansion(long long x, int m) {
	vector<int> exp;
	while (x > 0) {
		exp.push_back(x % m);
		x /= m;
	}
	return exp;
}
// 루카스의 정리
long long lucas_thm(long long n, long long k, int m) {
	long long ans = 1;
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

int main() {
	// init memo with -1
	for (int i = 0; i < 2001; i++) {
		for (int j = 0; j < 2001; j++) {
			memo[i][j] = -1;
		}
	}
	long long n, k;
	int m;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k >> m;

	cout << lucas_thm(n, k, m) << "\n";
	return 0;
}