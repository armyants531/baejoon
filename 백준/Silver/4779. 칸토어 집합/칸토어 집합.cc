#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void sol(int n) {
	if (n == 0) {
		cout << '-';
	}
	else {
		sol(n - 1);
		for (int i = 0; i < pow(3, n - 1); i++) {
			cout << ' ';
		}
		sol(n - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	while (cin >> n) {
		sol(n);
		cout << "\n";
	}
	return 0;
}