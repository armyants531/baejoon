// 교수님은 기다리지 않는다  // disjoint set  // Union-Find Alg
#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> diff; // 루트 노드와의 무게 차이를 저장!

int get_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	int p = get_parent(parent[x]);
	diff[x] += diff[parent[x]]; // 조상부터 차례로 더해나감
	return parent[x] = p;
}

void union_parent(int x, int y, int w) {
	int x_root = get_parent(x);
	int y_root = get_parent(y);
	parent[y_root] = x_root; // y_root의 부모를 x_root로 설정
	diff[y_root] = diff[x] + w - diff[y];
}

bool same_parent(int x, int y) {
	return get_parent(x) == get_parent(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	while (N != 0) {
		parent.clear();
		diff.clear();
		parent.resize(N + 1);
		diff.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < M; i++) {
			char c;
			int a, b, w;
			cin >> c;
			if (c == '!') {
				cin >> a >> b >> w;
				if (a != b) {
					union_parent(a, b, w); // w >= 0
				}
			}
			else {
				cin >> a >> b;
				if (same_parent(a, b)) {
					cout << diff[b] - diff[a] << "\n";
				}
				else {
					cout << "UNKNOWN" << "\n";
				}
			}
		}
		cin >> N >> M;
	}
}