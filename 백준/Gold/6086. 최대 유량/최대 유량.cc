// 최대 유량  // flow network
// https://m.blog.naver.com/ndb796/221237111220 참고
#include <bits/stdc++.h>
#define int long long
#define MAX 52
#define MAX_FLOW 1001

using namespace std;

int ca[MAX][MAX]; // 용량
int fl[MAX][MAX]; // 현재 유량 
int visited[MAX]; // 방문 경로 및 방문 여부  
vector<int> adj[MAX]; // adj list
int ans = 0;

void max_flow(int start, int end) {
	while (true) {
		fill(visited, visited + MAX, -1);
		queue<int> que;
		que.push(start);
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			for (auto next : adj[cur]) {
				// 방문 x && 용량 남음
				if (visited[next] == -1 && ca[cur][next] > fl[cur][next]) {
					que.push(next);
					visited[next] = cur; // 경로 기록
					if (next == end) {
						break;
					}
				}
			}
		}
		if (visited[end] == -1) break; // 더 이상 탐색 x
		int flow = MAX_FLOW;
		// 반대 방향으로 최소 유량 탐색
		for (int i = end; i != start; i = visited[i]) {
			flow = min(flow, ca[visited[i]][i] - fl[visited[i]][i]);
		}
		// 최소 유량 추가
		for (int i = end; i != start; i = visited[i]) {
			fl[visited[i]][i] += flow; // 양의 유량
			fl[i][visited[i]] -= flow; // 음의 유량
		}
		ans += flow;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	char a, b;
	int c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		int A = a - 'A';
		int B = b - 'A';
		if (A >= 32) {
			A -= 6;
		}
		if (B >= 32) {
			B -= 6;
		}
		adj[A].push_back(B);
		adj[B].push_back(A);
		ca[A][B] += c;
		ca[B][A] += c;
	}
	max_flow(0, 25);
	cout << ans << "\n";

	return 0;
}