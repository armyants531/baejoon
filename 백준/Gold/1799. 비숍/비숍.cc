// Bishop  // backtracking  // dfs
// https://j2wooooo.tistory.com/80 참고
#include <bits/stdc++.h>

using namespace std;

vector<int> board[10];
vector<int> cross1(20, 0); // 왼쪽 위 - 오른쪽 아래 대각선 리스트
vector<int> cross2(20, 0); // 오른쪽 위 - 왼쪽 아래 대각선 리스트
int ans = 0;
int N;

// y행 x열에 bishop 배치 
void dfs(int cnt, int y, int x) {
	// y가 N-1을 넘어가면 종료
	if (y > N - 1) {
		ans = max(ans, cnt);
		return;
	}
	// 비숍 배치 가능 && 왼쪽 위 - 오른쪽 아래 대각선 방향에 비숍 X && 오른쪽 위 - 왼쪽 아래 대각선 방향에 비숍 X
	if (board[y][x] == 1 && cross1[y - x + N - 1] == 0 && cross2[y + x] == 0) {
		cross1[y - x + N - 1] = 1;
		cross2[y + x] = 1;
		if (x + 2 > N - 1) { // 다음 칸이 보드를 넘어가면
			if (x % 2 == 0) { // 짝수열이면
				// 다음에는 홀수열(1열)
				dfs(cnt + 1, y + 1, 1);
			}
			else { // 홀수열이면
				// 다음에는 짝수열(0열)
				dfs(cnt + 1, y + 1, 0);
			}
		}
		else {
			dfs(cnt + 1, y, x + 2); // 현재 칸과 같은 색깔의 다음 칸으로 이동
		}
		cross1[y - x + N - 1] = 0;
		cross2[y + x] = 0;
	}
	// 이번 칸에 비숍 배치를 하지 않고 넘어가는 경우 고려
	if (x + 2 > N - 1) { // 다음 칸이 보드를 넘어가면
		if (x % 2 == 0) { // 짝수열이면
			// 다음에는 홀수열(1열)
			dfs(cnt, y + 1, 1);
		}
		else { // 홀수열이면
			// 다음에는 짝수열(0열)
			dfs(cnt, y + 1, 0);
		}
	}
	else {
		dfs(cnt, y, x + 2); // 현재 칸과 같은 색깔의 다음 칸으로 이동
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int val;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> val;
			board[i].push_back(val);
		}
	}
	dfs(0, 0, 0); // 검은 칸 dfs
	int ans_sum = ans;
	ans = 0; // ans 초기화
	dfs(0, 0, 1); // 흰 칸 dfs
	ans_sum += ans;
	cout << ans_sum << "\n";

	return 0;
}