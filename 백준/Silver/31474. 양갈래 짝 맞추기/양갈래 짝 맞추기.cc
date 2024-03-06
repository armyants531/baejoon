#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N;
	cin >> N;
	ll mul = 1;
	for (ll i = 1; i < N; i+=2) {
		mul *= i;
	}
	cout << mul << "\n";
	
	return 0;
}