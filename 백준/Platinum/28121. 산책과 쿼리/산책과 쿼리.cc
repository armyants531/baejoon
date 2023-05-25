// 산책과 쿼리  // disjoint set
// 어떠한 분리집합에 홀수개의 정점으로 이루어진 싸이클이 존재하면 
// 그 분리집합의 모든 원소는 자유도가 높다(N << t인 조건에서)
#include <bits/stdc++.h>

using namespace std;

vector<int> parent(600001);
vector<int> tree_size(600001, 1); // 분리 집합(트리)의 크기 저장
int N, Q;

int get_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = get_parent(parent[x]);
}

void union_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x == y) {
		return;
	}
	if (tree_size[x] > tree_size[y]) {
		tree_size[x] += tree_size[y];
		parent[y] = x;
	}
	else {
		tree_size[y] += tree_size[x];
		parent[x] = y;
	}
}

bool same_parent(int x, int y) { return get_parent(x) == get_parent(y); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> Q;
	// parent 배열 초기화
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 300001; i <= N + 300000; i++) {
		parent[i] = i;
	}
	// 각 정점 x를 짝수 시각(x0), 홀수 시각(x1) 정점으로 나누고 
	// 두 정점의 번호 x, y가 주어지면 x0와 y1연결 x1과 y0연결
	// 이후 x0와 x1이 연결되어있으면 산책의 자유도가 높은 것 
	// 해당 분리 집합의 원소들은 모두 자유도가 높다
	int x, y;
	set<int> s; // 부모 번호 저장하는 집합
	for (int i = 0; i < Q; i++) {
		cin >> x >> y;
		// 홀수 시각에 해당하는 정점은 300000을 더해 표현
		union_parent(x, y + 300000);
		union_parent(x + 300000, y);
		if (same_parent(x, x + 300000)) { // x0와 x1이 연결되어있으면
			s.insert(get_parent(x)); 
		}
		// set 순회하며 홀수 분리 집합의 원소 개수의 합 계산
		int cnt = 0;
		set<int> s2; // get_parent(*iter)에는 중복되는 값 존재 가능하므로 이를 제거
		for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
			s2.insert(get_parent(*iter));
		}
		for (set<int>::iterator iter = s2.begin(); iter != s2.end(); iter++) {
			cnt += tree_size[*iter] / 2; // 노드의 개수가 2배가 되었으므로 2로 나누어야 함
		}

		cout << cnt << "\n";
	}

	return 0;
}