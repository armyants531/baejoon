// 1로 만들기  // dp(tabulation)
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
}