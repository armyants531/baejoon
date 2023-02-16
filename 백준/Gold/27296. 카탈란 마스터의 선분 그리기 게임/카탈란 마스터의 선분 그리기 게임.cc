#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		ll N;
		cin >> N;
		if (N == 0 || N == 1) {
			cout << 1 << " " << 0 << "\n";
		}
		else {
			cout << 0 << " " << 1 << "\n";
		}
	}
}