#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	double num = 1;
	for (double i = N - 1; i >= 1; i--) {
		num += N / i;
	}
	cout << fixed;
	cout.precision(19);
	cout << num;

	return 0;
}