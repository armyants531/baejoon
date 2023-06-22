// 스티커  // dp
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int table[2][100002];
int point[2][100002]; // point[i][j] : table[i][j]를 선택했을 때 지금까지 점수의 최댓값

void tabulation(int n) {
	for (int i = 2; i <= n + 1; i++) {
		point[0][i] = max(point[1][i - 1], point[1][i - 2]) + table[0][i];
		point[1][i] = max(point[0][i - 1], point[0][i - 2]) + table[1][i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n; 
		cin >> n;
		for (int i = 2; i <= n + 1; i++) {
			point[0][i] = 0;
			point[1][i] = 0;
		}
		for (int i = 2; i <= n + 1; i++) {
			cin >> table[0][i];
		}
		for (int i = 2; i <= n + 1; i++) {
			cin >> table[1][i];
		}
		tabulation(n);
		cout << max({point[0][n], point[0][n + 1], point[1][n], point[1][n + 1] }) << "\n";
	}

	return 0;
}