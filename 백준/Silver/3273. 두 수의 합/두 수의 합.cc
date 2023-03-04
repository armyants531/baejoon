#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  int start = 0;
  int end = N - 1;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int x;
  cin >> x;
  sort(A.begin(), A.end());
  int sum = 0;
  ll cnt = 0;
  while (start < end) {
    sum = A[start] + A[end];
    if (sum == x) {
      cnt++;
      start++;
      end--;
    }
    else if (sum > x) {
      end--;
    }
    else {
      start++;
    }
  }
  cout << cnt << "\n";
}