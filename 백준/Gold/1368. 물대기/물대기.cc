// 물대기  // MST
// 우물을 파는데 드는 비용을 간선으로 가지는 가상의 노드 생성!
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// edge
struct edge {
	int node1;
	int node2;
	int weight;
};

// parent node info array
int parent[301]; // 0 ~ n
vector<vector<int>> arr(300, vector<int>(300));

bool compare(const edge& e1, const edge& e2) {
	return e1.weight < e2.weight;
}

int get_parent(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = get_parent(parent[x]);
}

void union_parent(int A, int B) {
	A = get_parent(A);
	B = get_parent(B);
	if (A < B)
		parent[B] = A;
	else
		parent[A] = B;
}

bool same_parent(int A, int B) {
	return get_parent(A) == get_parent(B);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> w(n);
	vector<edge> graph;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			graph.push_back({i, j, arr[i][j]});
		}
	}
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	// 우물을 파는데 드는 비용을 간선으로 가지는 가상의 N번 노드 생성
	for (int i = 0; i < n; i++) {
		graph.push_back({i, n, w[i]});
	}
	sort(graph.begin(), graph.end(), compare);
	int sum = 0;
	for (int i = 0; i < n * (n + 1) / 2; i++) { // edge 수: n * (n + 1)개
		int node1 = graph[i].node1;
		int node2 = graph[i].node2;
		if (!same_parent(node1, node2)) {
			sum += graph[i].weight;
			union_parent(node1, node2);
		}
	}
	cout << sum << "\n";

	return 0;
}