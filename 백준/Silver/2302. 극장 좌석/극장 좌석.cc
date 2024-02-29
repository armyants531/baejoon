#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

vector<int> fib(41);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	fib[0] = 1;
	fib[1] = 1;
	fib[2] = 2;
	vector<int> a(m + 2);
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	a[m+1] = n+1;
	for (int i = 3; i <= 40; i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}
	int ans = 1;
	for (int i = 1; i <= m+1; i++) {
		ans *= fib[a[i] - a[i-1] - 1];
	}
	cout << ans << "\n";
	return 0;
}