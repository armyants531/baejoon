// 구간 합 구하기 5  // dp  // prefix_sum
#include <bits/stdc++.h>

using namespace std;

long long table[1026][1026] = { 0, }; // normal
long long table1[1026][1026] = { 0, }; // prefix_sum left-up
long long table2[1026][1026] = { 0, }; // prefix_sum right-down;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	long long total_sum = 0;
	long long val;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> val;
			table[i][j] = val;
			total_sum += val;
		}
	}
	// fill out table1
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			table1[i][j] = table[i][j] + table1[i - 1][j] + table1[i][j - 1] - table1[i - 1][j - 1];
		}
	}
	// fill out table2
	for (int i = N; i >= 1; i--) {
		for (int j = N; j >= 1; j--) {
			table2[i][j] = table[i][j] + table2[i + 1][j] + table2[i][j + 1] - table2[i + 1][j + 1];
		}
	}
	long long sum;
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// 좌상 큰 정사각형 + 우하 큰 정사각형 + 좌하 작은 정사각형 + 우상 작은 정사각형 - 전체 합 = 좌상 큰 정사각형과 우하 큰 정사각형의 겹치는 부분 합
		sum = table1[x2][y2] + table2[x1][y1] + (table1[N][y1 - 1] - table1[x2][y1 - 1]) + (table2[1][y2 + 1] - table2[x1][y2 + 1]) - total_sum; 
		cout << sum << "\n";
	}

	return 0;
}