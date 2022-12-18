// 행렬 찾기  // 누적 합
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
	vector<vector<int>> matrix(N + 1, vector<int>(M)); // 0행을 0으로 만들기 위해 N+1개의 행을 만듦
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			matrix[i][j] = (int)(s[j] - '0');
		}
	}
	int max_area = 0;
	// matrix[i][j] == 0인 경우 자기 자신을 포함하여 그 위에 있는 0의 개수를 matrix[i][j]에 저장(0 개수의 누적합)
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][j] = matrix[i - 1][j] + 1;
			}
			else { // matrix[i][j] == 1
				matrix[i][j] = 0;
			}
			if (matrix[i][j] != 0) {
				int height = matrix[i][j]; // 직사각형의 높이
				// j ~ 0까지 k를 옮겨가면서 최대 넓이 갱신
				for (int k = j; k >= 0; k--) {
					int width = j - k + 1; // 직사각형의 너비
					height = min(height, matrix[i][k]); // 높이 갱신(가능한 높이 중 최대)
					max_area = max(max_area, height * width);
				}
			}
		}
	}
	cout << max_area << "\n";
	/*
	// test code
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cout << matrix[i][j];
		}
		cout << "\n";
	}
	*/

	return 0;
}