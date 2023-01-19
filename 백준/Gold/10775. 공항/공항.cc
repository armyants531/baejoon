// 공항  // greedy  // disjoint set
// if docking is possible union 'gate' with 'gate - 1'
#include <bits/stdc++.h>

using namespace std;

vector<int> parent(100001);

// if get_parent returns 0, there is no available gate
int get_parent(int x) {
  if (parent[x] == x) {
    return x;
  }
  return parent[x] = get_parent(parent[x]);
}

// x < y
void union_parent(int x, int y) {
  x = get_parent(x);
  y = get_parent(y);
  parent[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int G, P;
  cin >> G >> P;
  // init parent arr
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}
  vector<int> arr(P + 1);
  for (int i = 1; i <= P; i++) {
    int g;
    cin >> g;
    arr[i] = g;
  }
  int cnt = 0;
  for (int i = 1; i <= P; i++) {
    int gate = get_parent(arr[i]);
    if (gate == 0) {
      break;
    } 
    union_parent(gate - 1, gate);  
    cnt++;
  }
  
  cout << cnt << "\n";
  
	return 0;
}