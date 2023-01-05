#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double b, c, a1, a2;
	cin >> b >> c >> a1 >> a2;
	double alp = (b + sqrt(b * b + 4 * c)) / 2;
	double bta = (b - sqrt(b * b + 4 * c)) / 2;
	cout << fixed;
	cout.precision(12);
	cout << alp;

	return 0;
}