// 깊콘이 넘쳐흘러  // greedy
// https://canoe726.tistory.com/30 참고
// 이전 구간의 최댓값보다 크고, 현 구간의 Bi 값 이상으로 사용기간 연장
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> arr(1000001);
vector<int> primes;

bool compare(pair<int, int> &a, pair<int, int> &b) {
  if (a.second == b.second) { // 2. Ai에 대해 오름차순
    return a.first < b.first;
  } 
  return a.second < b.second; // 1. Bi에 대해 오름차순
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int N;
  cin >> N;
  vector<pair<int, int>> arr(N, {0, 0});
  for (int i = 0; i < N; i++) {
    cin >> arr[i].first;
  }
  for (int i = 0; i < N; i++) {
    cin >> arr[i].second;
  }
  sort(arr.begin(), arr.end(), compare);
  // 같은 Bi 값을 가진 것끼리 구간을 나눔
  int max_pre = arr[0].second; // 이전 구간의 최댓값
  int max_cur = 0; // 현재 구간의 최댓값
  ll cnt = 0;
  // 현재 Ai 값이 
  // 1 ~ i - 1 구간의 갱신된 Ai의 최댓값보다 작거나 
  // 1 ~ i 구간의 Bi의 최댓값 보다 작으면 현재 Ai 값을 갱신 
  for (int i = 0; i < N; i++) {
    if (arr[i].first < max_pre) {
      max_pre = max(max_pre, arr[i].second);
      //cout << "max_pre : " << max_pre << "\n";
      int num = ceil((double)(max_pre - arr[i].first) / 30);
      //cout << "num : " << num << "\n";
      cnt += num;
      arr[i].first += num * 30;
    }
    max_cur = max(max_cur, arr[i].first); // 현재 구간의 최댓값 갱신
    // 다음 구간으로 넘어갈 때 (Bi != Bi+1) pre 갱신
    if (i + 1 < N && arr[i].second != arr[i+1].second) {
      max_pre = max_cur;
    }
  }
  cout << cnt << "\n";

  return 0;
}