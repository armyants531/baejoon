// 방사형 그래프  // geometry
#include <bits/stdc++.h>

using namespace std;

vector<int> ability(9);
vector<vector<int>> List;

void dfs(int node, int cnt, vector<bool> visited, vector<int> order) {
  visited[node] = true;
  order.push_back(node);
  if (cnt == 8) {
    List.push_back(order);
    return;
  }
  cnt++;
  for (int i = 1; i <= 8; i++) {
    if (!visited[i]) {
      dfs(i, cnt, visited, order);
    }
  } 
}

bool check(double a, double b, double c) {
  return b >= sqrt(2) * a * c / (a + c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  for (int i = 1; i <= 8; i++) {
    int a;
    cin >> a;
    ability[i] = a;
  }
  for (int i = 1; i <= 8; i++) {
    vector<bool> visited(9);
    vector<int> order;
    dfs(i, 1, visited, order);
  }
  int cnt = 0;
  for (int i = 0; i < List.size(); i++) {
    bool isOK = true;
    for (int mid = 0; mid < 8; mid++) {
      if (mid == 0) {
        isOK = check(ability[List[i][7]], ability[List[i][0]], ability[List[i][1]]);
      }
      else if (mid == 7) {
        isOK = check(ability[List[i][6]], ability[List[i][7]], ability[List[i][0]]);
      }
      else {
        isOK = check(ability[List[i][mid - 1]], ability[List[i][mid]], ability[List[i][mid + 1]]);
      }
      if (!isOK) {
        break;
      }
    }
    if (isOK) {
      cnt++;
    }
  }
  cout << cnt << "\n";
  
	return 0;
}