#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// a^n mod p  // 빠른 거듭제곱 알고리즘
ll moduler(ll a, ll n, ll p) {
	ll val = 1;

	while (n) {
		if (n % 2 == 1)
			val = a * val % p;
		a = (a * a) % p;	
		n /= 2;
	}

	return val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;
	if (N == 0) {
		cout << 1 << "\n";
	}
	else {
		cout << moduler(2, N-1, 1000000007) << "\n";
	}

	return 0;
}