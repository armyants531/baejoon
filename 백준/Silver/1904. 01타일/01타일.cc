// 01타일  // dp  // tabulation
#include <bits/stdc++.h>

using namespace std;

vector<int> table(1000001);

int dp(int N) {
	table[1] = 1;
	table[2] = 2;
	for (int i = 3; i <= N; i++) {
		table[i] = (table[i - 1] + table[i - 2]) % 15746;
	}
	return table[N];
}

int main() {
	int N;
	cin >> N;
	cout << dp(N) << "\n";
	
	return 0;
}