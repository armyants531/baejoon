// 링크 컷 토마토  // dijkstra

#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define INF 2147483647

using namespace std;
using pii = pair<int, int>;

struct link {
	int T, x, y;
};

bool cmp(link A, link B) {
	return A.T < B.T;
}

vector<link> A;
vector<vector<int>> adj(200001);
// in[a][b]: a와 b가 연결된 상태가 되는 시간 저장하는 배열
// out[a][b]: a와 b가 연결이 끊긴 상태가 되는 시간 저장하는 배열
map<int, map<int, vector<int>>> in, out;

int next_time(int t, int x, int y) {
	if (x > y) swap(x, y);
	if (in[x][y].size() == 0) return INF;

	int in_idx = upper_bound(in[x][y].begin(), in[x][y].end(), t) - in[x][y].begin();
	if (in_idx == 0) return in[x][y][0] + 1; // 하루 후 전파
	in_idx--; // t보다 큰 시간의 최솟값보다 작은 시간 가르킴
	int out_idx = upper_bound(out[x][y].begin(), out[x][y].end(), t) - out[x][y].begin();
	if (out_idx == 0) return t + 1; // t일 때 연결된 상태이므로 t + 1에 전파
	out_idx--;
	if (in[x][y][in_idx] >= out[x][y][out_idx]) return t + 1;
	else { // t일 때 연결되지 않은 상태
		in_idx++;
		if (in_idx == in[x][y].size()) { // t 이후 연결된 상태가 존재하지 않으면
			return INF;
		}
		else {
			return in[x][y][in_idx] + 1;
		}
	}
}

vector<int> dijkstra(vector<int> X, int N) {
	vector<int> dist(N + 1, INF); // 도달 시간 저장 배열	
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i < X.size(); i++) {
		pq.push({ 0, X[i]});
		dist[X[i]] = 0;
	}
	while (!pq.empty()) {
		int cur_node = pq.top().se;
		int cur_dist = pq.top().fi;
		pq.pop();
		if (dist[cur_node] < cur_dist) continue;
		for (int next_node : adj[cur_node]) {
			if (dist[next_node] > cur_dist + 1) { // 현재 시간 + 1 보다 크면 갱신 가능 여부 확인
				int nt = next_time(cur_dist, cur_node, next_node); // 다음 시간 찾기
				if (dist[next_node] > nt) { // 시간 개선이 되었으면
					dist[next_node] = nt;
					pq.push({nt, next_node});
				}
			}
		}
	}
	return dist;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
		int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		in[a][b].push_back(0);
	}
	vector<int> X(K);
	for (int i = 0; i < K; i++) {
		cin >> X[i];
	}
	int T, x, y;
	for (int i = 0; i < Q; i++) {
		cin >> T >> x >> y;
		A.push_back({ T, x, y });
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	sort(A.begin(), A.end(), cmp);
	// 각 간선이 언제 이어지고 끊기는지 map으로 기록
	for (link &l : A) {
		if (in[l.x][l.y].size() == 0) {
			in[l.x][l.y].push_back(l.T);
		}
		else if (out[l.x][l.y].size() == 0) {
			out[l.x][l.y].push_back(l.T);
		}
		else if (in[l.x][l.y].back() < out[l.x][l.y].back()) {
			in[l.x][l.y].push_back(l.T);
		}
		else {
			out[l.x][l.y].push_back(l.T);
		}
	}
	
	vector<int> dist = dijkstra(X, N);
	for (int i = 1; i <= N; i++) {
		if (dist[i] == INF) {
			cout << -1 << " ";
		}
		else {
			cout << dist[i] << " ";
		}	
	}
	cout << "\n";
	return 0;
}