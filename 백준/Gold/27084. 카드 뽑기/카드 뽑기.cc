#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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
	std::cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a]++;
	}

	ll x = 1;
	ll sum = n;
	for (int i = 1; i <= n; i++) {
		if (arr[i] >= 2) {
			x *= (arr[i] + 1);
			x %= p;
			sum -= arr[i];
		}
	}
	//cout << sum << "\n";
	//cout << power(2, sum) << "\n";
	ll ans = x * power(2, sum) - 1;
	cout << (ans + p) % p << "\n";

	return 0;
}