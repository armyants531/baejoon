// 개구리  // sweeping
#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;
vector<int> parent(100001);

struct leep {
	int x, y, num;
};

// sort: x에 대해 오름차순
bool cmp(leep a, leep b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

// set: y에 대해 오름차순
struct y_order {
	bool operator() (const leep& a, const leep& b) const {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		return a.y < b.y;
	}
};

int get_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = get_parent(parent[x]);
}

void union_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x < y) {
		parent[y] = x;
	}
	else {
		parent[x] = y;
	}
}

bool same_parent(int x, int y) {
	return get_parent(x) == get_parent(y);
}

void solve(vector<leep> p, int N, int r, int d) {
	sort(p.begin(), p.end(), cmp); // x좌표 기준 오름차순 정렬
	set<leep, y_order> posi; // y좌표에 대해 오름차순
	int left = 0, right = 0; // 다음 지울 시작점, 다음 탐색 시작점 
	for (int i = 0; i < N; i++) {
		leep cur = p[i];
		while (right < N && p[right].x <= cur.x + r) { // [x, x + r] 범위에 속해 있는 점 삽입
			posi.insert(p[right]);
			right++;
		}
		while (left < right && p[left].x < cur.x) { // 현재 x좌표 미만인 점 삭제
			posi.erase(p[left]);
			left++;
		}
		auto it = posi.upper_bound({ -1, cur.y + r, -1 });
		for (int j = 0; j < 2; j++) {
			if (it != posi.end()) {
				leep g = *it;
				if (g.y <= cur.y + r + d) {
					union_parent(cur.num, g.num);
				}
				it++;
			}
		}
		it = posi.upper_bound({ -1, cur.y - r, 0 });
		for (int j = 0; j < 2; j++) {
			if (it != posi.begin()) {
				it--;
				leep g = *it;
				if (g.y >= cur.y - r - d) {
					union_parent(cur.num, g.num);
				}
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, r;
	cin >> N >> r;
	vector<leep> p(N);
	vector<leep> p2(N);
	int x, y, d;
	int idx0 = -1;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		if (x == 0 && y == 0) {
			idx0 = i;
		}
		p[i].x = x;
		p[i].y = y;
		p2[i].x = y;
		p2[i].y = x;
	}
	if (idx0 != 0) { // {0, 0}의 번호는 0
		swap(p[0], p[idx0]);
		swap(p2[0], p2[idx0]);
	}
	for (int i = 0; i < N; i++) {
		p[i].num = i;
		p2[i].num = i;
	}
	cin >> d;
	// parent initializing
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
	// x좌표 기준으로 오름차순 정렬하여 탐색
	solve(p, N, r, d);
	/*
	for (int i = 0; i < N; i++) {
		cout << parent[i] << " ";
	} 
	cout << "\n";
	*/
	// y좌표 기준으로 오름차순 정렬하여 탐색(x, y가 바뀜)
	solve(p2, N, r, d);
	/*
	for (int i = 0; i < N; i++) {
		cout << parent[i] << " ";
	}
	cout << "\n";
	*/
	int max_v = 0;
	for (int i = 1; i < N; i++) {
		if (same_parent(0, i)) {
			max_v = max(max_v, p[i].x + p[i].y);
		}
	}
	cout << max_v + 2 * r << "\n";

	return 0;
}