#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	if (a + b <= c) {
		cout << (a + b) * 2 - 1 << "\n";
	}
	else if (a + c <= b) {
		cout << (a + c) * 2 - 1 << "\n";
	}
	else if (b + c <= a) {
		cout << (b + c) * 2 - 1 << "\n";
	}
	else {
		cout << a + b + c << "\n";
	}
}