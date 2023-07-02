#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;
typedef long long ll;

struct gear {
	double x, y, r;
};

struct edge {
	int node1;
	int node2;
	double weight;
};

int parent[1001]; // 0 ~ n

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
	int N;
	cin >> N;
	double x, y, r;
	vector<gear> a(N);
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> r;
		a[i] = { x, y, r };
	}
	vector<edge> graph;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double l = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
			double len;
			if (l <= a[i].r + a[j].r) {
				len = 0;
			}
			else {
				double ang = 2 * acos((a[i].r - a[j].r) / l);
				len = 2 * l * sin(ang / 2) + (2 * M_PI - ang) * a[i].r + ang * a[j].r;
			}	
			graph.push_back({ i, j, len });
		}
	}
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
	sort(graph.begin(), graph.end(), compare);
	double sum = 0;
	for (int i = 0; i < graph.size(); i++) {
		int node1 = graph[i].node1;
		int node2 = graph[i].node2;
		if (!same_parent(node1, node2)) {
			sum += graph[i].weight;
			union_parent(node1, node2);
		}
	}
	cout << fixed;
	cout.precision(12);
	cout << sum << "\n";

	return 0;
}