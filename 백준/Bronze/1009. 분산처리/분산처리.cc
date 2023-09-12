#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		a %= 10;	
		if (a == 1 || a == 5 || a == 6) {
			cout << a << "\n";
		}	
		else if (a == 2) {
			b %= 4;
			if (b == 1) {
				cout << 2 << "\n";	
			}
			else if (b == 2) {
				cout << 4 << "\n";
			}
			else if (b == 3) {
				cout << 8 << "\n";
			}
			else {
				cout << 6 << "\n";
			}
		}
		else if (a == 3) {
			b %= 4;
			if (b == 1) {
				cout << 3 << "\n";	
			}
			else if (b == 2) {
				cout << 9 << "\n";
			}
			else if (b == 3) {
				cout << 7 << "\n";
			}
			else {
				cout << 1 << "\n";
			}
		}
		else if (a == 7) {
			b %= 4;
			if (b == 1) {
				cout << 7 << "\n";	
			}
			else if (b == 2) {
				cout << 9 << "\n";
			}
			else if (b == 3) {
				cout << 3 << "\n";
			}
			else {
				cout << 1 << "\n";
			}
		}
		else if (a == 8) {
			b %= 4;
			if (b == 1) {
				cout << 8 << "\n";	
			}
			else if (b == 2) {
				cout << 4 << "\n";
			}
			else if (b == 3) {
				cout << 2 << "\n";
			}
			else {
				cout << 6 << "\n";
			}
		}
		else if (a == 4) {
			b %= 2;
			if (b == 1) {
				cout << 4 << "\n";	
			}
			else {
				cout << 6 << "\n";
			}	
		}
		else if (a == 9) {
			b %= 2;
			if (b == 1) {
				cout << 9 << "\n";	
			}
			else {
				cout << 1 << "\n";
			}	
		}
		else { // a == 0
			cout << 10 << "\n";	
		}
	}
	
	return 0;
}