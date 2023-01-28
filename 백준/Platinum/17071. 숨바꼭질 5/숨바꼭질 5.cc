// 숨바꼭질 5  // bfs
// https://dongchans.github.io/2019/53/ 참고
// 같은 곳을 재방문할 수 있음
#include <bits/stdc++.h>

using namespace std;

// visited[n][0] : 위치 n을 방문한 최소 짝수 시간
// visited[n][1] : 위치 n을 방문한 최소 홀수 시간
vector<vector<int>> visited(500001, vector<int>(2, -1));
int N, K;

// 이동 가능한 지점 모두 방문
void bfs() {
	queue<pair<int, int>> que; // {위치, 시간}
	que.push({ N, 0 });
	visited[N][0] = 0;
	while (!que.empty()) {
		int x = que.front().first;
		int t = que.front().second;
		que.pop();
		int x2 = x * 2;
		t++;
		int flag = t % 2;
		if (x2 <= 500000 && visited[x2][flag] == -1) {
			que.push({ x2, t });
			visited[x2][flag] = t;
		}
		if (x + 1 <= 500000 && visited[x + 1][flag] == -1) {
			que.push({ x + 1, t });
			visited[x + 1][flag] = t;
		}
		if (x - 1 >= 0 && visited[x - 1][flag] == -1) {
			que.push({ x - 1, t });
			visited[x - 1][flag] = t;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	bfs();
	int T = 0;
	bool find = false;
	while (K <= 500000) {
		if (visited[K][T % 2] != -1 && visited[K][T % 2] <= T) {
			cout << T << "\n";
			find = true;
			break;
		}
		T++;
		K += T;
	}
	if (!find) {
		cout << -1 << "\n";
	}

	return 0;
}