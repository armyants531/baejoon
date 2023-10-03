#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int gcd(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A, B;
	cin >> A >> B;
	if (A < B) swap(A, B);
	int g = gcd(A, B);
	cout << g << "\n";
	cout << A * B / g << "\n";
	
	return 0;
}