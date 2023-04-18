#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	int a, b, c, d;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		a = n / 25;
		n %= 25;
		b = n / 10;
		n %= 10;
		c = n / 5;
		n %= 5;
		d = n;
		cout << a << " " << b << " " << c << " " << d << "\n";
	}
	
	return 0;
}