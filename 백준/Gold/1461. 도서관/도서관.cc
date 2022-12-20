// 도서관  // greedy  // sort
#include <bits/stdc++.h>
#include <deque>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M;
  cin >> N >> M;
  vector<int> neg;
  vector<int> pos;
  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;
    if (val < 0) {
      neg.push_back(-val);
    }
    else {
      pos.push_back(val);
    }
  }
  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end());

  deque<int> posD;
  deque<int> negD;
  
  for (int i = 0; i < pos.size(); i++) {
    posD.push_back(pos[i]);
  }
  for (int i = 0; i < neg.size(); i++) {
    negD.push_back(neg[i]);
  }
  // cal distance
  int dist = 0;
  int pos_d = 0;
  int neg_d = 0;
  if (!posD.empty()) {
    pos_d = posD.back();
  }
  if (!negD.empty()) {
    neg_d = negD.back();
  }
  for (int i = 0; i < M; i++) {
    if (!posD.empty()) {
      posD.pop_back();
    }
    if (!negD.empty()) {
      negD.pop_back();
    }
  }
  dist += max(neg_d, pos_d) + min(neg_d, pos_d) * 2;
  pos_d = 0;
  neg_d = 0;
  while (!negD.empty()) {
    neg_d = negD.back();
    for (int i = 0; i < M; i++) {
      if (!negD.empty()) {
        negD.pop_back();
      }
    }
    dist += neg_d * 2;
  }
  while (!posD.empty()) {
    pos_d = posD.back();
    for (int i = 0; i < M; i++) {
      if (!posD.empty()) {
        posD.pop_back();
      }
    }
    dist += pos_d * 2;
  }
  cout << dist << "\n";
  
  return 0;
}