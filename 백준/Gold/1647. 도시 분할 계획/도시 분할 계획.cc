// 도시 분할 계획  // Kruskal 알고리즘 
// 최소 생성 트리를 만들어 cost 합을 구하고 
// 트리를 이루는 경로 중 cost가 가장 큰 것을 빼주면 된다.
#include <bits/stdc++.h>

using namespace std;

struct edge {
	int node1;
	int node2;
	int cost;
};

vector<int> parent(100001);

bool compare(edge& e1, edge& e2) {
	return e1.cost < e2.cost;
}

int get_parent(int node) {
	if (parent[node] == node) {
		return node;
	}
	else {
		return parent[node] = get_parent(parent[node]);
	}
}

void union_parent(int node1, int node2) {
	node1 = get_parent(node1);
	node2 = get_parent(node2);
	if (node1 < node2) {
		parent[node2] = node1;
	}
	else {
		parent[node1] = node2;
	}
}

bool same_parent(int node1, int node2) {
	return get_parent(node1) == get_parent(node2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<edge> graph;
	int A, B, C;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		graph.push_back({ A, B, C });
	}
	sort(graph.begin(), graph.end(), compare);

	int sum = 0;
	int max_cost = 0;
	for (int i = 0; i < M; i++) { // for all of the edge 
		int node1 = graph[i].node1;
		int node2 = graph[i].node2;
		// if not generating a cycle(not having same parent)
		if (!same_parent(node1, node2)) {
			int cost = graph[i].cost;
			sum += cost;
			if (max_cost < cost) {
				max_cost = cost;
			}
			union_parent(node1, node2);
		}
	}
	cout << sum - max_cost << "\n";
	return 0;
}