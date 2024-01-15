#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int gcd(int a, int b) { 
    return b % a == 0 ? a : gcd(b % a, a);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	if (N % K == 0) {
		cout << 0 << "\n";
	}
	else {
		int g = gcd(N, K);
		cout << N / g * (min(K / g, (N-K) / g) - 1) << "\n";
	}
	
	return 0;
}