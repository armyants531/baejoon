// 행성 터널  // Kruskal 알고리즘
#include <bits/stdc++.h>

using namespace std;

// planet
struct planet {
    int num; // 생성 번호
    int x;
    int y;
    int z;
};

// edge
struct edge {
    int node1; // 행성 번호 1
    int node2; // 행성 번호 2 
    //planet A;
    //planet B;
    int weight;
};

// parent node info array
int parent[100001];

bool compare_x(const planet& planet1, const planet& planet2) {
    return planet1.x < planet2.x;
}

bool compare_y(const planet& planet1, const planet& planet2) {
    return planet1.y < planet2.y;
}

bool compare_z(const planet& planet1, const planet& planet2) {
    return planet1.z < planet2.z;
}

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

int calc_weight(planet A, planet B) {
    int x_len = abs(A.x - B.x);
    int y_len = abs(A.y - B.y);
    int z_len = abs(A.z - B.z);
    int min_cost;
    if (x_len > y_len)
        min_cost = y_len;
    else
        min_cost = x_len;
    if (min_cost > z_len)
        min_cost = z_len;

    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V; // 정점의 수: V
    cin >> V;
    vector<planet> planets;
    vector<edge> graph;
    int x, y, z;
    for (int i = 0; i < V; i++) {
        cin >> x >> y >> z;
        planets.push_back({ i, x, y, z });
    }
    sort(planets.begin(), planets.end(), compare_x);
    edge temp;
    for (int i = 0; i < V - 1; i++) { // 인접한 노드의 좌표 차이 구하기
        temp.node1 = planets[i].num;
        temp.node2 = planets[i + 1].num;
        temp.weight = calc_weight(planets[i], planets[i + 1]);
        graph.push_back(temp);
    }
    sort(planets.begin(), planets.end(), compare_y);
    for (int i = 0; i < V - 1; i++) { // 인접한 노드의 좌표 차이 구하기
        temp.node1 = planets[i].num;
        temp.node2 = planets[i + 1].num;
        temp.weight = calc_weight(planets[i], planets[i + 1]);
        graph.push_back(temp);
    }
    sort(planets.begin(), planets.end(), compare_z);
    for (int i = 0; i < V - 1; i++) { // 인접한 노드의 좌표 차이 구하기
        temp.node1 = planets[i].num;
        temp.node2 = planets[i + 1].num;
        temp.weight = calc_weight(planets[i], planets[i + 1]);
        graph.push_back(temp);
    }
    sort(graph.begin(), graph.end(), compare);

    // Union-Find Alg
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }
    // init the sum of weight
    int sum = 0;
    for (int i = 0; i < graph.size(); i++) { // for all of the edge 
        int node1 = graph[i].node1;
        int node2 = graph[i].node2;
        // if not generating a cycle(not having same parent)
        if (!same_parent(node1, node2)) {
            sum += graph[i].weight;
            union_parent(node1, node2);
        }
    }
    cout << sum << "\n";

    return 0;
}