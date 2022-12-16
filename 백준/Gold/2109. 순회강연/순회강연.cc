// 순회강연  // greedy  // priority queue
#include <bits/stdc++.h>

using namespace std;

struct compare {
  bool operator()(pair<int, int> A, pair<int, int> B) {
    return A.first < B.first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> que[10001];
  vector<pair<int, int>> arr;
  int p, d;
  int max_d = 0;
  for (int i = 0; i < N; i++) {
    cin >> p >> d;
    max_d = max(max_d, d);
    que[d].push({p, d});
  }
  int money = 0;
  for (int i = max_d; i >= 1; i--) {
    int max_val = 0;
    int max_idx = -1;
    for (int j = max_d; j >= i; j--) {
      if (!que[j].empty() && max_val < que[j].top().first) {
        max_idx = j;
        max_val = que[j].top().first;
      }
    }
    if (max_idx != -1) {
      money += que[max_idx].top().first;
      que[max_idx].pop();
    }
  }
  cout << money << "\n";

  return 0;
}