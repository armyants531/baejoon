// 우선순위와 쿼리  // disjoint set  // tree set
#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef long long ll;

struct compare {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		if (a.first == b.first) {
			return a.second < b.second; // 오름차순
		}
		return a.first > b.first; // 내림차순
	}
};

int parent[100001];
bool cycle[100001];
vector<int> tree_size(100001, 1); // 분리집합의 크기 저장
set<pair<int, int>, compare> s; // 탐색할 트리 목록 <크기, 최소 번호>

int get_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = get_parent(parent[x]);
}

void union_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	s.erase({ tree_size[x], x });
	s.erase({ tree_size[y], y });
	if (x == y) {
		cycle[x] = true; // cycle을 이루게 된 부모 노드 체크
		return;
	}
	// merge big root number tree to small root number tree
	if (x < y) {	
		parent[y] = x;
		tree_size[x] += tree_size[y];
		if (cycle[x] || cycle[y]) {
			cycle[x] = true;
			cycle[y] = true;
			return;
		}
		else { // if there is no cycle(tree)
			s.insert({ tree_size[x], x });
		}
	}
	else {	
		parent[x] = y;
		tree_size[y] += tree_size[x];
		if (cycle[x] || cycle[y]) {
			cycle[x] = true;
			cycle[y] = true;
			return;
		}
		else { // if there is no cycle(tree)
			s.insert({ tree_size[y], y });
		}
	}
}

bool same_parent(int x, int y) {
	return get_parent(x) == get_parent(y);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		s.insert({ 1, i });
	}
	int ord, u, v;
	for (int i = 0; i < Q; i++) {
		cin >> ord;
		if (ord == 1) {
			cin >> u >> v;
			union_parent(u, v);
		}
		else {
			// 우선 순위가 가장 높은 것은 set의 맨 앞
			set<pair<int, int>>::iterator it = s.begin();
			pair<int, int> x = *it;
			cout << x.second << "\n";
			s.erase(x);
		}
	}

	return 0;
}