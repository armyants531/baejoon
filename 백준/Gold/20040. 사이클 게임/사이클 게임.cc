// 사이클 게임  // disjoint set
#include <bits/stdc++.h>

using namespace std;

vector<int> parent(500001);

int get_parent(int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = get_parent(parent[x]);
}

void union_parent(int x, int y) {
  x = get_parent(x);
  y = get_parent(y);
  if (x < y) parent[y] = x;
  else parent[x] = y;
}

bool same_parent(int x, int y) {
  return get_parent(x) == get_parent(y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int num = 0;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (!same_parent(a, b)) {
      union_parent(a, b);
    }
    else if (num == 0) {
      num = i + 1;
    }
  }
  cout << num << "\n";
}