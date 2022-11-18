// 최소 스패닝 트리  // Kruskal 알고리즘  
// https://m.blog.naver.com/ndb796/221230994142 참고
#include <bits/stdc++.h>

using namespace std;

// edge
struct edge {
  int node1;
  int node2;
  int weight;
};
// parent node info array
int parent[10001];

bool compare(const edge& e1, const edge& e2) {
  return e1.weight < e2.weight;
}

// Union-Find Alg
// get parent node of x
int get_parent(int x) {
  if (parent[x] == x)
    return x;
  else 
    return parent[x] = get_parent(parent[x]);
}

// merge each parent node
void union_parent(int A, int B) {
  A = get_parent(A);
  B = get_parent(B);
  if (A < B) 
    parent[B] = A;
  else
    parent[A] = B;
}

// check if A and B have the same parent node
bool same_parent(int A, int B) {
  return get_parent(A) == get_parent(B);
}

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int V, E;
  cin >> V >> E;
  vector<edge> graph;
  int A, B, C;
  for (int i = 0; i < E; i++) {
    cin >> A >> B >> C;
    graph.push_back({A, B, C});
  }
  sort(graph.begin(), graph.end(), compare);
  // Union-Find Alg
  for (int i = 1; i <= V; i++) {
    parent[i] = i;
  }
  // init the sum of weight
  int sum = 0;
  for (int i = 0; i < E; i++) { // for all of the edge 
    // if not generating a cycle
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