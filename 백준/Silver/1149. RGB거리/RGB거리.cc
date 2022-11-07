// RGB거리  // tabulation
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int arr[1000][3];
  int cost[1000][3];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> arr[i][j];
    }
  }
  // cost calc
  for (int i = 0; i < 3; i++) {
    cost[0][i] = arr[0][i];
  }
  for (int i = 1; i < n; i++) { // i >= 1 이면 이전에 선택할 수 있는 두 가지
    // 방법 중 cost가 최소인 값에 현재 선택 색상에 따른 cost 더함
    cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + arr[i][0];
    cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + arr[i][1];
    cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + arr[i][2];
  }
  int cost1 = cost[n - 1][0];
  int cost2 = cost[n - 1][1];
  int cost3 = cost[n - 1][2];
  if (cost1 <= cost2 && cost1 <= cost3)
    cout << cost1 << "\n";
  else if (cost2 <= cost1 && cost2 <= cost3)
    cout << cost2 << "\n";
  else
    cout << cost3 << "\n";

  return 0;
}