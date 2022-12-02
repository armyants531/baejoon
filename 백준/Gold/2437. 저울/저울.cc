// 저울  // greedy  // sort
// 추를 오름차순 정렬한 후, 추 무게의 누적합이 다음추 무게보다 2이상 작으면, 추 무게의 누적합 + 1한 값이 측정할 수 없는 값이다.
// 처음 추 무게가 1이 아니라면 1이 측정 불가하고, 추 전체 무게의 합 + 1은 항상 측정 불가하다.
#include <bits/stdc++.h>

using namespace std;

vector<int> weights;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int w;
    cin >> w;
    weights.push_back(w);
  }
  // increasing order
  sort(weights.begin(), weights.end());
  
  int ans = 0;
  if (weights[0] != 1) {
    cout << 1 << "\n";
  }
  else {
    ans++;
    for (int i = 1; i < N; i++) {
      if (ans + 1 < weights[i]) {
        break;
      }
      else {
        ans += weights[i];
      }
    }
    cout << ans + 1 << "\n";
  }
  
  return 0;
}