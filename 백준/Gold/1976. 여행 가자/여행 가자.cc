// 여행 가자  // disjoint set  // Union-Find Alg
#include <bits/stdc++.h>

using namespace std;

vector<int> parent(201);
vector<vector<int>> adj(201, vector<int>(201));

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
  // init parent
  for (int i = 1; i <= N; i++) {
    parent[i] = i;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int num;
      cin >> num;
      if (num) { // num == 1
        union_parent(i, j);
      }
    }
  }
  bool isPossible = true;
  int a, b;
  cin >> a;
  for (int i = 1; i < M; i++) {
    cin >> b;
    if (!same_parent(a, b)) {
      isPossible = false;
    }
  }
  if (isPossible) {
    cout << "YES" << "\n";
  }
  else {
    cout << "NO" << "\n";
  }
}