// 행렬 제곱  // 선형대수학  // 분할 정복
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// 행렬곱 함수
vector<vector<ll>> matrix_mult(vector<vector<ll>> matrix1, vector<vector<ll>> matrix2, ll c) {
	int N = matrix1.size();
	int M = matrix1[0].size();
	int K = matrix2[0].size();
	vector<vector<ll>> matrix3(N, vector<ll>(K, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int k = 0; k < M; k++) {
				matrix3[i][j] += matrix1[i][k] * matrix2[k][j] % c;
			}
			matrix3[i][j] %= c;
		}
	}
	return matrix3;
}

// a의 b거듭제곱을 c로 나눔
vector<vector<ll>> power(vector<vector<ll>> matrix, ll b, ll c) {
	if (b == 1) {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				matrix[i][j] %= c;
			}
		}
		return matrix;
	}
	vector<vector<ll>> pow = power(matrix, b / 2, c);
	if (b % 2 == 0) {
		return matrix_mult(pow, pow, c);
	}
	else {
		return matrix_mult(matrix_mult(pow, pow, c), matrix, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	ll B;
	cin >> N >> B;
	vector<vector<ll>> matrix(N, vector<ll>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
	vector<vector<ll>> result = power(matrix, B, 1000);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
} 