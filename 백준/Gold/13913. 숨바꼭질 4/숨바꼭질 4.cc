// 숨바꼭질 4  // bfs
// bfs 수행 중 이미 방문한 위치는 또 방문할 필요 없음(최소 시간을 구하기 때문) 
#include <bits/stdc++.h>

using namespace std;

int min_time = 100001;
vector<bool> visited(100001, false);
vector<int> previ(100001); // prev[curr] = pre: 이전 좌표를 알려줌

int bfs(int start, int end) {
	queue<pair<int, int>> que; // {위치, 시간}
	que.push({ start, 0 });
	while (!que.empty()) {
		int x = que.front().first;
		int t = que.front().second;
		que.pop();
		visited[x] = true;
		if (x == end) {
			return t;
		}
		if (x * 2 <= 100000 && !visited[x * 2]) {
			que.push({ x * 2, t + 1 });
			if (previ[x * 2] == 0) 
				previ[x * 2] = x;
		}
		if (x + 1 <= 100000 && !visited[x + 1]) {
			que.push({x + 1, t + 1});
			if (previ[x + 1] == 0) // 나중에 다시 덮어씌우는 경우 막기 위해
				previ[x + 1] = x;
		}
		if (x - 1 >= 0 && !visited[x - 1]) {
			que.push({ x - 1, t + 1 });
			if (previ[x - 1] == 0)
				previ[x - 1] = x;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	int T = bfs(N, K);
	cout << T << "\n";
	stack<int> st;
	st.push(K);
	while (K != N) {
		K = previ[K];
		st.push(K);
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << "\n";

	return 0;
}