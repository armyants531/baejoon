// 별자리 만들기  // Kruskal 알고리즘  
#include <bits/stdc++.h>

using namespace std;

// edge
struct edge {
	int node1;
	int node2;
	double weight;
};

int parent[100];

// get parent node of x
int get_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = get_parent(parent[x]);
	}
}

// merge each parent node
void union_parent(int A, int B) {
	A = get_parent(A);
	B = get_parent(B);
	if (A < B) {
		parent[B] = A;
	}
	else {
		parent[A] = B;
	}
}

// check if A and B have the same parent node
bool same_parent(int A, int B) {
	return get_parent(A) == get_parent(B);
}

bool compare(edge& e1, edge& e2) {
	return e1.weight < e2.weight;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<edge> graph;
	vector<pair<double, double>> point;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		point.push_back({x, y});
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			double A = (point[i].first - point[j].first);
			double B = (point[i].second - point[j].second);
			double len = sqrt(A * A + B * B);
			graph.push_back({i, j, len});
		}
	}
	sort(graph.begin(), graph.end(), compare);
	// Union-Find Alg
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	// init the sum of weight
	double sum = 0;
	for (int i = 0; i < graph.size(); i++) { // for all of the edge 
		// if not generating a cycle(not having same parent)
		int node1 = graph[i].node1;
		int node2 = graph[i].node2;
		if (!same_parent(node1, node2)) {
			sum += graph[i].weight;
			union_parent(node1, node2);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << sum << "\n";
}