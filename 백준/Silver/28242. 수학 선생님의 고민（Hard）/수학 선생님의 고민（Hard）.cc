#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	ll det = 5 * n * n + 10 * n + 1;
	ll sq = sqrt(det);
	if (sq * sq == det) {
		ll up1 = n + 1 - sq;
		ll up2 = n + 1 + sq;
		ll n1, n2; // n = n1 * n2;
		bool can = false;
		for (int i = 1; i <= sqrt(n); i++) {
			if (n % i == 0) {
				n1 = i;
				n2 = n / i;
				if (up1 % (2 * n1) == 0 && up2 % (2 * n2) == 0) {
					cout << n2 << " " << up1 / (2 * n1) << " " << n1 << " " << up2 / (2 * n2) << "\n";
					can = true;
					break;
				}
				else if (up2 % (2 * n1) == 0 && up1 % (2 * n2) == 0) {
					cout << n2 << " " << up2 / (2 * n1) << " " << n1 << " " << up1 / (2 * n2) << "\n";
					can = true;
					break;
				}
			}
		}
		if (!can) {
			cout << -1 << "\n";
		}	
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}