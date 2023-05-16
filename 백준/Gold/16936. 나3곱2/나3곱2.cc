// 나3곱2  // math  // sort
// 인수로 3을 많이 갖는 순서대로 정렬
// 3의 개수가 같으면 오름차순 정렬
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct num {
  ll x;
  int cnt;
};

vector<num> A;
int N;

bool compare(const num &a, const num &b) {
  if (a.cnt == b.cnt) {
    return a.x < b.x; // x에 대해 오름차순
  }
  return a.cnt > b.cnt; // cnt에 대해 내림차순
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  ll a;
  for (int i = 0; i < N; i++) {
    cin >> a;
    ll b = a;
    int cnt = 0; // 3으로 몇 번 나누어 떨어지는지 세기
    while (b % 3 == 0) {
      b /= 3;
      cnt++;
    }
    A.push_back({a, cnt});
  }
  sort(A.begin(), A.end(), compare);
  for (int i = 0; i < N; i++) {
    cout << A[i].x << " ";
  }
  cout << "\n";
  
  return 0;
}