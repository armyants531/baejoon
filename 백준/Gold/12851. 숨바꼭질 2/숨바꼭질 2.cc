// 숨바꼭질 2  // bfs
#include <bits/stdc++.h>

using namespace std;

int min_time = 100001;
int min_cnt = 0;
vector<bool> visited(100001, false);

void bfs(int start, int end) {
	queue<pair<int, int>> que; // {위치, 시간}
	que.push({ start, 0 });
	while (!que.empty()) {
		int x = que.front().first;
		int t = que.front().second;
		que.pop();
		visited[x] = true;
		if (min_time < t) {
			continue;
		}
		if (x == end) {
			if (min_time > t) {
				min_time = t; // 최소 시간 갱신
				min_cnt = 1; // 다시 카운트
			}
			else if (min_time == t) {
				min_cnt++;
			}
		}
		else {
			if (x * 2 <= 100000 && !visited[x * 2]) {
				que.push({x * 2, t + 1});
			}
			if (x - 1 >= 0 && !visited[x - 1]) {
				que.push({ x - 1, t + 1 });
			}
			if (x + 1 <= 100000 && !visited[x + 1]) {
				que.push({ x + 1, t + 1 });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	bfs(N, K);
	cout << min_time << "\n";
	cout << min_cnt << "\n";

	return 0;
}