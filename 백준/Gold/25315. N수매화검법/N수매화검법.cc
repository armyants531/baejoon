#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj(2501);
vector<int> inDegree(2501);
vector<int> ans(2501);

// CCW(counter clockwise)
// 세 점이 일직선 위에 있는 경우 x
struct coord { //coordinate
	ll x;
	ll y;
};

int CCW(coord A, coord B, coord C) {
	// overflow prevention
	// (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
	ll val = B.x * C.y - B.x * A.y - A.x * C.y - B.y * C.x + A.x * B.y + A.y * C.x;
	if (val > 0)
		return 1;
	else if (val < 0)
		return -1;
	else
		return 0;
}

void topologySort(int n) {
	queue<int> que;
	// insert the nodes which have 0 indegree
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			que.push(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		// if queue is empty before visit n node
		if (que.empty()) {
			return;
		}
		int node = que.front();
		que.pop();
		ans[i] = node;
		for (auto next : adj[node]) {
			inDegree[next]--;
			if (inDegree[next] == 0) {
				que.push(next);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	vector<ll> sx(N);
	vector<ll> sy(N);
	vector<ll> ex(N);
	vector<ll> ey(N);
	vector<ll> w(N);
	vector<bool> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> sx[i] >> sy[i] >> ex[i] >> ey[i] >> w[i];
	}
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			coord A, B, C, D;
			A = { sx[i], sy[i] };
			B = { ex[i], ey[i] };
			C = { sx[j], sy[j] };
			D = { ex[j], ey[j] };
			// AB를 기준으로 점 C, D의 CCW 확인
			int sign1 = CCW(A, B, C) * CCW(A, B, D);
			// CD를 기준으로 점 A, B의 CCW 확인
			int sign2 = CCW(C, D, A) * CCW(C, D, B);
			if (sign1 == -1 && sign2 == -1) { // 교차
				if (w[i] > w[j]) {
					adj[j].push_back(i);
				}
				else {
					adj[i].push_back(j);
				}
				arr[i] = true;
				arr[j] = true;
			}
		}
	}
	topologySort(N);
	for (int i = 0; i < N; i++) {
		sum += (adj[i].size() + 1) * w[i];
	}
	cout << sum << "\n";

	return 0;
}