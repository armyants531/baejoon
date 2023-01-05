#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	ll mul = 1;
	for (int i = 2; i <= n; i++) {
		mul *= i;
		mul %= 1000000007;
	}
	cout << mul << "\n";
	return 0;
}