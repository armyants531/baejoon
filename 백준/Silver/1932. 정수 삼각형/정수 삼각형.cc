// 정수 삼각형  // dp  // tabulation
#include <bits/stdc++.h>

using namespace std;

long long table[500][500];
int n;

long long sum(int row) {
	while (row > 0) {
		// table을 아래에서부터 차례대로 채워나감
		for (int i = 0; i < row; i++) {
			table[row - 1][i] += max(table[row][i], table[row][i + 1]);
		}
		row--;
	}
	return table[0][0]; // answer
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> table[i][j];
		}
	}
	cout << sum(n - 1) << "\n";
}