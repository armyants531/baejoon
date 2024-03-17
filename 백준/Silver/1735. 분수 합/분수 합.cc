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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int A = a * d + b * c;
	int B = b * d;
	cout << A / gcd(A, B) << " " << B / gcd(A, B) << "\n";
	
	return 0;
}