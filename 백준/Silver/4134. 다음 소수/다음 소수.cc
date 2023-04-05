#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	ll n;
	for (int t = 0; t < T; t++) {
		ll pri;
		cin >> n;
		pri = n;
		if (n == 0 || n == 1) {
			cout << 2 << "\n";
		}
		else {
			while (true) {
				bool isPrime = true;
				for (ll i = 2; i <= sqrt((long double)pri); i++) {
					if (pri % i == 0) {
						isPrime = false;
						break;	
					}	
				}
				if (isPrime) {
					cout << pri << "\n";  
					break;
				}
				else {
					pri++;
				}
			}
		}
	}
	return 0;
}