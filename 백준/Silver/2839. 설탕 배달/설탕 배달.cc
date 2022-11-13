// 설탕 배달  // dp(tabulation)  // math
#include <bits/stdc++.h>

using namespace std;

int table[5001] = { 0, }; // bottom-up

int main() {
	int N;
	cin >> N;
	table[3] = 1;
	table[5] = 1;

	for (int i = 6; i <= N; i++) {
		if (table[i - 5]) {
			table[i] = table[i - 5] + 1;
		}
		else if (table[i - 3]) {
			table[i] = table[i - 3] + 1;
		}
	}
	if (table[N] != 0)
		cout << table[N] << "\n";
	else
		cout << -1 << "\n";
}