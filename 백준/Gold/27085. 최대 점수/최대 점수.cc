// 최대 점수(upgraded)  // greedy  // two-pointer 
// start의 왼쪽과 end의 오른쪽에 대해 점수가 현재보다 처음으로 높아지는 지점을 각각 구한 후, 이동할 수 있는 방향으로 이동하는 것을 반복
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int N, s;
  cin >> N >> s;
  vector<ll> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  int left = s;
  int right = s;
  ll sum = 0;
  ll left_sum = 0;
  ll right_sum = 0;
  while (true) {
    ll last_sum = sum;
    // while the left is inside the range and tot is not negative
    while (left >= 2 && (A[left - 1] + left_sum + sum >= 0)) {
      left_sum += A[left - 1];  // add to left_sum
      left--;
      if (left_sum > 0) { // if the left sum is pos
        sum += left_sum;
        left_sum = 0;
        break;
      }
    }
    // while the right is inside the range and tot is not negative
    while (right <= N-1 && (A[right + 1] + right_sum + sum >= 0)) {
      right_sum += A[right + 1];
      right++;
      if (right_sum > 0) { // if the right sum is pos
        sum += right_sum;
        right_sum = 0;
        break;
      }
    }
    if (last_sum == sum) { // if the sum wasn't changed
      break;
    }
  }
  cout << sum << "\n";
  
	return 0;
}