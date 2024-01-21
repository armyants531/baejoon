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
	vector<int> A(6), B(6), C(6);
	for (int i = 0; i < 6; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 6; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < 6; i++) {
		cin >> C[i];
	}
	int a = 3600 * (A[3] - A[0]) + 60 * (A[4] - A[1]) + (A[5] - A[2]);
	int b = 3600 * (B[3] - B[0]) + 60 * (B[4] - B[1]) + (B[5] - B[2]);
	int c = 3600 * (C[3] - C[0]) + 60 * (C[4] - C[1]) + (C[5] - C[2]);
	cout << a / 3600 << " ";
	a %= 3600;
	cout << a / 60 << " ";
	a %= 60;
	cout << a << "\n";
	cout << b / 3600 << " ";
	b %= 3600;
	cout << b / 60 << " ";
	b %= 60;
	cout << b << "\n";
	cout << c / 3600 << " ";
	c %= 3600;
	cout << c / 60 << " ";
	c %= 60;
	cout << c << "\n";
	return 0;
}