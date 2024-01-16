#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int gcd(int a, int b) { 
    return b % a == 0 ? a : gcd(b % a, a);
}

int modular_inverse(int a, int m) {
	if (gcd(a, m) != 1) {
		return -1;
	}
	int s1 = 1;
	int s2 = 0;
	int t1 = 0;
	int t2 = 1;
	while (true) {
		int q = a / m;
		int r = a - q * m;
		int s = s1 - q * s2;
		int t = t1 - q * t2;
		if (r == 0) break;
		s1 = s2;
        s2 = s;
        t1 = t2;
        t2 = t;
        a = m;
        m = r;
	}	
	return s2;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, A;
	cin >> N >> A;
	int inv1 = N - A;
	int inv2 = modular_inverse(A, N);
	if (inv2 != -1 && inv2 < 0) {
		inv2 += N;
	} 
	cout << inv1 << " " << inv2 << "\n";
	
	return 0;
}