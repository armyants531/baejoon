// 로프 // greedy
// 로프가 버틸 수 있는 최대 중량을 정렬한 후, 로프를 하나씩 사용하지 않으면서 최대 중량 갱신
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;
    arr.push_back(val);
  }
  sort(arr.begin(), arr.end());
  int max_weight = 0;
  for (int i = 0; i < N; i++) {
    int weight = arr[i]*(N-i);
    if (max_weight < weight) {
      max_weight = weight;
    }
  }  
  cout << max_weight << "\n";
  return 0;
}