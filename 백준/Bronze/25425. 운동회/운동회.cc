#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, M, a, K;
	cin >> N >> M >> a >> K;
	ll MIN;
	if ((a - K) % M == 0) {
		MIN = (a - K) / M + 1;
	}
	else {
		MIN = (a - K) / M + 2;
	}
	if (a - K < N) {
		cout << a - K + 1 << " " << MIN << "\n";
	}
	else { // a - K >= N
		cout << N << " " << MIN << "\n";
	}
}