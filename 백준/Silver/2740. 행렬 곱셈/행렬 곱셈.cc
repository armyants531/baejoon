// 행렬 곱셈  // 선형대수학
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M;
	vector<vector<int>> matrix1(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> matrix1[i][j];
		}
	}
	cin >> M >> K;
	vector<vector<int>> matrix2(M, vector<int>(K));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> matrix2[i][j];
		}
	}
	vector<vector<int>> matrix3(N, vector<int>(K, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
			}
			cout << matrix3[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}