// 직사각형으로 나누기  // prefix sum
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<ll>> arr;
vector<vector<ll>> prefix_sum1;
vector<vector<ll>> prefix_sum2;
ll MAX = 0;

void divide1(int N, int M) {
	for (int i = 1; i <= M - 2; i++) {
		for (int j = i + 1; j <= M - 1; j++) {
			MAX = max(MAX, prefix_sum1[N][i] * (prefix_sum1[N][j] - prefix_sum1[N][i]) * (prefix_sum1[N][M] - prefix_sum1[N][j]));
		}
	}
}

void divide2(int N, int M) {
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 1; j++) {
			MAX = max(MAX, prefix_sum1[i][j] * (prefix_sum1[N][j] - prefix_sum1[i][j]) * (prefix_sum1[N][M] - prefix_sum1[N][j]));
		}
	}
}

void divide3(int N, int M) {
	for (int i = N; i >= 2; i--) {
		for (int j = M; j >= 2; j--) {
			MAX = max(MAX, prefix_sum2[i][j] * (prefix_sum2[1][j] - prefix_sum2[i][j]) * (prefix_sum2[1][1] - prefix_sum2[1][j]));
		}
	}
}

void divide4(int N, int M) {
	for (int i = 1; i <= N - 2; i++) {
		for (int j = i + 1; j <= N - 1; j++) {
			MAX = max(MAX, prefix_sum1[i][M] * (prefix_sum1[j][M] - prefix_sum1[i][M]) * (prefix_sum1[N][M] - prefix_sum1[j][M]));
		}
	}
}

void divide5(int N, int M) {
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= M - 1; j++) {
			MAX = max(MAX, prefix_sum1[i][j] * (prefix_sum1[i][M] - prefix_sum1[i][j]) * (prefix_sum1[N][M] - prefix_sum1[i][M]));
		}
	}
}

void divide6(int N, int M) {
	for (int i = N; i >= 2; i--) {
		for (int j = M; j >= 2; j--) {
			MAX = max(MAX, prefix_sum2[i][j] * (prefix_sum2[i][1] - prefix_sum2[i][j]) * (prefix_sum2[1][1] - prefix_sum2[i][1]));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	arr.resize(N + 2, vector<ll>(M + 2));
	prefix_sum1.resize(N + 2, vector<ll>(M + 2));
	prefix_sum2.resize(N + 2, vector<ll>(M + 2));
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = str[j - 1] - '0';
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			prefix_sum1[i][j] = prefix_sum1[i - 1][j] + prefix_sum1[i][j - 1] - prefix_sum1[i - 1][j - 1] + arr[i][j];
			//cout << prefix_sum1[i][j] << " ";
		}
		//cout << "\n";
	}
	for (int i = N; i >= 1; i--) {
		for (int j = M; j >= 1; j--) {
			prefix_sum2[i][j] = prefix_sum2[i + 1][j] + prefix_sum2[i][j + 1] - prefix_sum2[i + 1][j + 1] + arr[i][j];
		}
	}
	divide1(N, M);
	divide2(N, M);
	divide3(N, M);
	divide4(N, M);
	divide5(N, M);
	divide6(N, M);
	cout << MAX << "\n";

	return 0;
}