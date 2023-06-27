// 나도리합  // disjoint set
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> parent(200001);
vector<ll> g_sum(200001);
vector<ll> g_mul(200001);

int get_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = get_parent(parent[x]);
}

ll union_parent(int x, int y) {
	x = get_parent(x);
	y = get_parent(y);
	if (x == y) {
		return g_mul[x];
	}
	else if (x < y) {
		parent[y] = x;
		g_mul[x] += g_mul[y] + g_sum[x] * g_sum[y];
		g_sum[x] += g_sum[y];
		return g_mul[x];
	}
	else { // x > y
		parent[x] = y;
		g_mul[y] += g_mul[x] + g_sum[x] * g_sum[y];
		g_sum[y] += g_sum[x];
		return g_mul[y];
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
	int s;
	for (int i = 1; i <= N; i++) {
		cin >> s;
		g_sum[i] = s;
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << union_parent(a, b) << "\n";
	}

	return 0;
}