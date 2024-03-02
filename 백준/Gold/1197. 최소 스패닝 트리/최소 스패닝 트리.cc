#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge {
	int node1;
	int node2;
	int weight;
}; 

vector<int> parent(10001);

bool cmp(edge A, edge B) {
	return A.weight < B.weight;
}

int get_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = get_parent(parent[x]);
	}
}

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

bool same_parent(int A, int B) {
	return get_parent(A) == get_parent(B);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int V, E;
	cin >> V >> E;
	vector<edge> v;
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		v.push_back({A, B, C});
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < E; i++) {
		int n1 = v[i].node1;
		int n2 = v[i].node2;
		if (!same_parent(n1, n2)) {
			sum += v[i].weight;
			union_parent(n1, n2);
		}
	}
	cout << sum << "\n";
	return 0;
}