// 네트워크 연결  // Kruskal 알고리즘  
#include <bits/stdc++.h>

using namespace std;

// edge
struct edge {
    int node1;
    int node2;
    int weight;
};
// parent node info array
int parent[1001];

bool compare(const edge& e1, const edge& e2) {
    return e1.weight < e2.weight; // 오름차순 정렬
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
    int N, M;
    cin >> N >> M;
    vector<edge> graph;
    int A, B, C;
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        graph.push_back({ A, B, C });
    }
    sort(graph.begin(), graph.end(), compare);
    // Union-Find Alg
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    // init the sum of weight
    int sum = 0;
    for (int i = 0; i < M; i++) { // for all of the edge 
        // if not generating a cycle(not having same parent)
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