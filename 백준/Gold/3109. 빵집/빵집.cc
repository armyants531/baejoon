// 빵집  // greedy  // dfs
// 가장 왼쪽 위에서부터 차례로 오른쪽 위 대각선->오른쪽->오른쪽 아래 대각선
// 순으로 파이프를 연결을 시도하고 성공하면 check를 하여 dfs를 중단한다.
#include <bits/stdc++.h>

using namespace std;

int R, C;
int cnt = 0;
bool check = false;
vector<vector<int>> arr(10001, vector<int>(501, 0));

void dfs(int x, int y) {
	arr[x][y] = 1; // 현재 위치에 파이프 설치
	if (y + 1 == C) {
		cnt++;
		check = true;
		return;
	}
	if (x >= 1 && arr[x-1][y+1] == 0 && !check) { // 오른쪽 위 대각선
		dfs(x - 1, y + 1);
	}
	if (arr[x][y+1] == 0 && !check) { // 오른쪽
		dfs(x, y + 1);
	}
	if (x + 1 < R && arr[x+1][y+1] == 0 && !check) { // 오른쪽 아래 대각선
		dfs(x + 1, y + 1);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < C; j++) {
			if (str[j] == 'x') {
				arr[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		dfs(i, 0);
		check = false; // 연결 여부 초기화
	}
	cout << cnt << "\n";

	return 0;
}