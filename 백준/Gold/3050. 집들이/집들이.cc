// 집들이  // 누적 합
// O(n^3)
#include <bits/stdc++.h>

using namespace std;

vector<long long> arr(100001);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> matrix(N + 1, vector<int>(M, 0)); // 0행을 0으로 만들기 위해 N+1개의 행을 만듦
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] == '.') {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = 1;
			}
		}
	}
	int max_perimeter = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (matrix[i][j] == 0) { // 0이면 위에서부터 연속한 0개수 저장
				matrix[i][j] = matrix[i - 1][j] + 1;
			}
			else { // 1이면 0 저장
				matrix[i][j] = 0;
			}
			// 둘레 갱신
			if (matrix[i][j] != 0) {
				int height = matrix[i][j]; // 직사각형의 높이
				// j ~ 0까지 k를 변경하며 둘레 갱신
				for (int k = j; k >= 0; k--) {
					if (matrix[i][k] == 0) {
						break;
					}
					height = min(height, matrix[i][k]);
					int width = j - k + 1;
					max_perimeter = max(max_perimeter, 2 * (height + width));
				}
			}
			//cout << max_perimeter;
		}
		//cout << "\n";
	}
	cout << max_perimeter - 1 << "\n";

	return 0;
}