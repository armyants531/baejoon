// 집합의 표현  // disjoint set  // Union-Find Alg
#include <bits/stdc++.h>

using namespace std;

vector<int> parent(1000001);

int get_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = get_parent(parent[x]); // parent[x]를 갱신해나감
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int x, a, b;
	// init parent arr
	for (int i = 0; i < n + 1; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> a >> b;
		if (x == 0) {
			union_parent(a, b);
		}
		else {
			if (same_parent(a, b)) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}
	}
	return 0;
}