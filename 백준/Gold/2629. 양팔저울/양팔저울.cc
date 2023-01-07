// 양팔저울  // dp  // knapsack problem
// dp[i][j] : i번 째 추까지 사용했을 때 무게가 j인 구슬을 확인할 수 있는지 여부  
// dp[i][j] = dp[i - 1][|j - ob[i]|] | dp[i - 1][j + ob[i]] | dp[i - 1][j]
#include <bits/stdc++.h>

using namespace std;

vector<int> ob;
vector<int> bead;
int dp[30][15501] = {0,};
int N, M;

void knapsack() {
  for (int i = 0; i < N; i++) {
    dp[i][0] = 1;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][ob[j]] = 1;
    }
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= 15000; j++) {
      if (dp[i][j]) continue;
      dp[i][j] = (dp[i - 1][abs(j - ob[i])] | dp[i - 1][j + ob[i]] | dp[i - 1][j]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) { 
    int a;
    cin >> a;
    ob.push_back(a);
  }
  cin >> M;
  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    bead.push_back(a);
  }
  knapsack();
  for (int i = 0; i < M; i++) {
    if (bead[i] > 15000) {
      cout << 'N' << " ";
    }
    else {
      if (dp[N - 1][bead[i]]) {
        cout << 'Y' << " ";
      }
      else {
        cout << 'N' << " ";
      }
    }
  }
  
  return 0;
}