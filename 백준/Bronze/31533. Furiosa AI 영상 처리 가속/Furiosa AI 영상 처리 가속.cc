#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	double a, m, n;
	cin >> a >> m >> n;
	double t1 = 0, t2 = 0;
	if (m > n) {
		double n2 = n / a;
		t1 = n2 * 2;
		t2 = max(m / a, n);
	} 
	else if (m <= n) {
		double m2 = m / a;
		t1 = m2 * 2;
		t2 = max(m, n / a);
	}
	cout << fixed;
	cout.precision(12);
	cout << min(t1, t2) << "\n";
	
	return 0;
}