// 과제   // greedy  // priority queue
#include <bits/stdc++.h>

using namespace std;

struct compare {
  bool operator()(pair<int, int> A, pair<int, int> B) {
    return A.second < B.second;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que[1001];
  vector<pair<int, int>> arr;
  int d, w;
  int max_d = 0;
  for (int i = 0; i < N; i++) {
    cin >> d >> w;
    max_d = max(max_d, d);
    que[d].push({d, w});
  }
  int score = 0;
  for (int i = max_d; i >= 1; i--) {
    int max_val = 0;
    int max_idx = -1;
    for (int j = max_d; j >= i; j--) {
      if (!que[j].empty() && max_val < que[j].top().second) {
        max_idx = j;
        max_val = que[j].top().second;
      }
    }
    if (max_idx != -1) {
      score += que[max_idx].top().second;
      que[max_idx].pop();
    }
  }
  cout << score << "\n";

  return 0;
}