#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, S;
	cin >> T >> S;
	if (T <= 11 || T >= 17 || S == 1) {
		cout << 280 << "\n";
	}
	else {
		cout << 320 << "\n";
	}
}