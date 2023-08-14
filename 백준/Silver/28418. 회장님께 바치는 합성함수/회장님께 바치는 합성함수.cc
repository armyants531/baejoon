#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
using pss = pair<string, string>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int A = a * d * (d - 1);
	int B = a * d * e;
	int C = a * e * e + b * e + c - c * d - e;
	if (A == 0 && B == 0 && C == 0) {
		cout << "Nice" << "\n";
	} 
	else if (A != 0) {
		int D = B * B - A * C;
		if (D > 0) {
			cout << "Go ahead" << "\n";
		}
		else if (D == 0) {
			cout << "Remember my character" << "\n";
		}
		else {
			cout << "Head on" << "\n";
		}
	}
	else if (B != 0) {
		cout << "Remember my character" << "\n";
	}
	else { // C != 0
		cout << "Head on" << "\n";
	}
	
	return 0;
}