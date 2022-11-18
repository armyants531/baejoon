// 1로 만들기 2  // dp(tabulation)
#include <bits/stdc++.h>

using namespace std;

vector<int> table(1000001);

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    table[i] = i - 1; // init table
  }
  for (int i = 2; i <= N; i++) {
    if (i % 3 == 0) {
      table[i] = min(table[i], table[i / 3] + 1);
    }
    if (i % 2 == 0) {
      table[i] = min(table[i], table[i / 2] + 1);
    }
    table[i] = min(table[i], table[i - 1] + 1);
  }
  cout << table[N] << "\n";
  cout << N << " ";
  // backtracking
  while (N > 1) {
    if (N % 3 == 0 && table[N] == table[N / 3] + 1) {
      N /= 3;
      cout << N << " ";
    }
    else if (N % 2 == 0 && table[N] == table[N / 2] + 1) {
      N /= 2;
      cout << N << " ";
    }
    else if (table[N] == table[N - 1] + 1) {
      N--;
      cout << N << " ";
    }
  }
  cout << "\n";
  
  return 0;
}