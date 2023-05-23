// 안전한 건설 계획  // 분리 집합
// 분리 집합의 개수를 구하면 된다
#include <bits/stdc++.h>

using namespace std;

vector<int> parent(41);
vector<int> cnt(41);

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		union_parent(a, b);
	}
	// parent에 연결된 노드 수 세기
	for (int i = 1; i <= N; i++) {
		cnt[get_parent(i)]++;
	}
	// 분리 집합 수 세기
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] != 0) ans++;
	}
	cout << ans - 1 << "\n";
	return 0;
}