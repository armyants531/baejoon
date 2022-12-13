// 기타줄  // greedy
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N >> M;
  int A_min = 1001; 
  int B_min = 1001;
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A_min = min(A_min, A);
    B_min = min(B_min, B);
  }
  int cost;
  if (A_min < B_min * 6) {
    int quotient = N / 6;
    int remainder = N % 6;
    if (remainder * B_min >= A_min) {
      cost = (quotient + 1) * A_min;
    }
    else {
      cost = quotient * A_min + remainder * B_min;  
    }
  }
  else {
    cost = N * B_min;
  }
  
  cout << cost << "\n";
  
  return 0;
}