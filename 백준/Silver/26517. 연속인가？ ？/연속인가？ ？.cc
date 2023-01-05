#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll k;
	cin >> k;
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a * k + b == c * k + d) {
		cout << "Yes " << a * k + b;
	}
	else {
		cout << "No";
	}
	return 0;
}