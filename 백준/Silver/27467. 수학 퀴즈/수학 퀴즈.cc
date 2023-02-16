#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	double p = 0;
	double q = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		a = a % 3;
		if (a == 0) {
			q++;
		}
		else if (a == 1) {
			p++;
		}
		else if (a == 2) {
			p--;
			q--;
		}
	}
	cout << fixed;
	cout.precision(9);
	cout << p << " " << q;
}