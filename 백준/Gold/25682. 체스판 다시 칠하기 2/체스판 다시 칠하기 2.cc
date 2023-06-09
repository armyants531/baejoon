// 체스판 다시 칠하기 2  // prefix sum
// https://jih3508.tistory.com/59 참고
// 맨 위 왼쪽이 흰색인 경우와 검은색인 경우로 나누어
// 체스판과 색이 일치하면 0, 일치하지 않으면 1로 표기하고 2차원 배열 누적합을 구한다
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int>> board1(N + 1, vector<int>(M + 1)); // 맨 왼쪽 위 흰 칸일 때
	vector<vector<int>> board2(N + 1, vector<int>(M + 1)); // 맨 왼쪽 위 검은 칸일 때
	string s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 1; j <= M; j++) {
			if (((i + j) % 2 == 0 && s[j - 1] == 'W') || (i + j) % 2 == 1 && s[j - 1] == 'B') {
				board1[i][j] = board1[i - 1][j] + board1[i][j - 1] - board1[i - 1][j - 1];
				board2[i][j] = board2[i - 1][j] + board2[i][j - 1] - board2[i - 1][j - 1] + 1;
			}
			else {
				board1[i][j] = board1[i - 1][j] + board1[i][j - 1] - board1[i - 1][j - 1] + 1;
				board2[i][j] = board2[i - 1][j] + board2[i][j - 1] - board2[i - 1][j - 1];
			}
		}
	}
	// K * K 보드 탐색
	int min_cnt = 4000000;
	for (int i = K; i <= N; i++) {
		for (int j = K; j <= M; j++) {
			min_cnt = min(min_cnt, board1[i][j] - board1[i - K][j] - board1[i][j - K] + board1[i - K][j - K]);
			min_cnt = min(min_cnt, board2[i][j] - board2[i - K][j] - board2[i][j - K] + board2[i - K][j - K]);
		}
	}
	cout << min_cnt << "\n";

	return 0;
}