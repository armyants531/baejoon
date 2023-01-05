// 이미지 보정 작업  // 이분 탐색  // 매개 변수 탐색  // 그래프 탐색
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node {
	int y;
	int x;
};

vector<vector<ll>> arr;
queue<node> que;
vector<vector<bool>> visited;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };


// 선명도의 가장 큰 차이를 mid이하로 만드는데 필요한 구역의 개수
int bfs(int y, int x, int N, int M, int K, ll X, ll mid) {
	bool revision = false;
	que.push({ y, x });
	visited[y][x] = true;
	int cnt = 1;
	while (!que.empty()) {
		int y = que.front().y;
		int x = que.front().x;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 <= ny && ny < N && 0 <= nx && nx < M && !visited[ny][nx]) { // 범위 내에 있고 방문하지 않았으면
				if (abs(arr[ny][nx] - arr[y][x]) > mid) {
					revision = true;
				}
				if (arr[ny][nx] < X - mid) {
					visited[ny][nx] = true; // 방문 처리
					que.push({ny, nx});
					cnt++;
				}
			}
		}
	}
	if (revision) {
		return cnt;
	}
	else {
		return 0;
	}
}

ll bSearch(ll low, ll high, int N, int M, int K, ll X) {
	ll mid;
	ll ans = 1000000000000000000;
	while (low <= high) {
		visited.clear();
		visited.resize(N, vector<bool>(M, false));
		mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (X - mid > arr[i][j] && !visited[i][j]) {
					cnt += bfs(i, j, N, M, K, X, mid);
				}
			}
		}
		if (cnt <= K) {
			// 선명도 차이 최솟값 갱신
			ans = min(ans, mid);
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	ll X;
	cin >> N >> M >> K >> X;
	arr.resize(N, vector<ll>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	cout << bSearch(0, 1000000000000000000, N, M, K, X) << "\n";

	return 0;
}