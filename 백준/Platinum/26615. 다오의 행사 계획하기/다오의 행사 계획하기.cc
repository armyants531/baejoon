// 다오의 행사 계획하기  // Tree  // LCA  // prefix sum
// {x, y}의 2^k(2의 k승)번째 부모: parent[x][y][k] = parent[parent[x][y][k - 1].first][parent[x][y][k - 1].second][k - 1]
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> A;
vector<vector<int>> B;
vector<vector<bool>> visited; 
vector<vector<int>> depth; // depth[x][y] : {x, y} 노드의 깊이
vector<vector<vector<pair<int, int>>>> parent; // 각 노드의 부모 저장
vector<vector<vector<int>>> dist; // dist[x][y][k] : {x, y}에서 2 ^ k번 째 조상까지의 거리
int max_depth = 18;
int N, M, T;

// 모든 노드의 깊이 구하기({0, 0}이 root)
void bfs() {
	visited[0][0] = true;
	depth[0][0] = 0; 
	queue<pair<int, int>> que;
	que.push({ 0, 0 });
	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		if (x + 1 <= N - 1 && !visited[x + 1][y] && A[x][y] == 0) {
			parent[x + 1][y][0] = {x, y};
			visited[x + 1][y] = true;
			depth[x + 1][y] = depth[x][y] + 1;
			dist[x + 1][y][0] = 1;
			que.push({ x + 1, y });
		}
		if (x - 1 >= 0 && !visited[x - 1][y] && A[x - 1][y] == 0) {
			parent[x - 1][y][0] = {x, y};
			visited[x - 1][y] = true;
			depth[x - 1][y] = depth[x][y] + 1;
			dist[x - 1][y][0] = 1;
			que.push({ x - 1, y });
		}
		if (y + 1 <= M - 1 && !visited[x][y + 1] && B[x][y] == 0) {
			parent[x][y + 1][0] = {x, y};
			visited[x][y + 1] = true;
			depth[x][y + 1] = depth[x][y] + 1;
			dist[x][y + 1][0] = 1;
			que.push({ x, y + 1 });
		}
		if (y - 1 >= 0 && !visited[x][y - 1] && B[x][y - 1] == 0) {
			parent[x][y - 1][0] = {x, y};
			visited[x][y - 1] = true;
			depth[x][y - 1] = depth[x][y] + 1;
			dist[x][y - 1][0] = 1;
			que.push({ x, y - 1 });
		}
	}
}

// {a, b}와 {c, d} 사이 거리 구하기(O(log n))
int distance(int a, int b, int c, int d) {
	int len = 0;
	// 두 노드의 깊이 맞추기
	if (depth[a][b] > depth[c][d]) {
		int diff = depth[a][b] - depth[c][d];
		//len += diff;
		for (int i = 0; diff > 0; i++) {
			if (diff % 2 == 1) {
				len += dist[a][b][i];
				int na = parent[a][b][i].first;
				int nb = parent[a][b][i].second;
				a = na;
				b = nb;
			}
			diff /= 2;
		}
	}
	else {
		int diff = depth[c][d] - depth[a][b];
		//len += diff;
		for (int i = 0; diff > 0; i++) {
			if (diff % 2 == 1) {
				len += dist[c][d][i];
				int nc = parent[c][d][i].first;
				int nd = parent[c][d][i].second;
				c = nc;
				d = nd;
			}
			diff /= 2;
		}
	}
	// 공통 조상 찾을 때까지 위로 올리기
	int i = max_depth;
	if (!(a == c && b == d)) {
		while (i >= 0) {
			if (parent[a][b][i].first != -1 && (parent[a][b][i] != parent[c][d][i])) {
				len += dist[a][b][i] + dist[c][d][i];
				int na = parent[a][b][i].first;
				int nb = parent[a][b][i].second;
				a = na;
				b = nb;
				int nc = parent[c][d][i].first;
				int nd = parent[c][d][i].second;
				c = nc;
				d = nd;
			}
			i--;
		}
		len += 2; // A의 부모가 공통 조상(+ 2)
	}
	return len;  
}

// parent, dist 전처리
void makeParent() {
	for (int k = 0; k < max_depth; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (parent[i][j][k].first != -1) {
					parent[i][j][k + 1] = parent[parent[i][j][k].first][parent[i][j][k].second][k];
					dist[i][j][k + 1] = dist[i][j][k] + dist[parent[i][j][k].first][parent[i][j][k].second][k];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> T;
	visited.resize(N, vector<bool>(M, false));
	A.resize(N - 1, vector<int>(M, 0));
	B.resize(N, vector<int>(M - 1, 0));
	depth.resize(N, vector<int>(M, 0));
	parent.resize(N, vector<vector<pair<int, int>>>(M, vector<pair<int, int>>(19, {-1, -1})));
	dist.resize(N, vector<vector<int>>(M, vector<int>(19)));
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			int val;
			cin >> val;
			A[i][j] = val;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) {
			int val;
			cin >> val;
			B[i][j] = val;
		}
	}
	bfs();
	// parent 초기화(전처리)
	makeParent();
	int K;
	cin >> K;
	vector<ll> arr(T + 2, 0); // 차이값 배열(누적합 이용)
	for (int i = 1; i <= K; i++) {
		int S, E, a, b, c, d, V;
		cin >> S >> E >> a >> b >> c >> d >> V;
		ll cnt = distance(a, b, c, d) + 1; // 1을 더해주어야 함 
		ll val = cnt * V;
		arr[S] += val;
		arr[E + 1] -= val;
		/*
		for (int j = S; j <= E; j++) { // 시간 초과
			arr[j] += cnt * V;
		}
		*/
	}
	ll prefix_sum = 0;
	for (int i = 1; i <= T; i++) {
		prefix_sum += arr[i];
		cout << prefix_sum << "\n";
	}

	return 0;
}