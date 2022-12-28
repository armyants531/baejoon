// 알고리즘 수업 - 피보나치 수 1  // dp
#include <bits/stdc++.h>

using namespace std;

vector<int> table(41);

int fibonacci(int n) {
	table[1] = 1;
	table[2] = 1;
	for (int i = 3; i <= n; i++) {
		table[i] = table[i - 1] + table[i - 2];
	}
	return table[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	fibonacci(n);
	cout << table[n] << " " << n - 2 << "\n";

	return 0;
}