// 주사위 세개  // math
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	if (a == b && b == c) {
		cout << 10000 + a * 1000 << "\n";
	}
	else if (a == b) {
		cout << 1000 + a * 100 << "\n";
	}
	else if (b == c) {
		cout << 1000 + b * 100 << "\n";
	}
	else if (c == a) {
		cout << 1000 + c * 100 << "\n";
	}
	else {
		cout << max({ a, b, c }) * 100 << "\n";
	}
}