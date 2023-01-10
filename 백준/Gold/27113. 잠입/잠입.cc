// 잠입  // greedy
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  int col = 1;
  bool posi = true;
  for (int i = 1; i < N; i++) {     
    int x;
    cin >> x;
    if (col > M) {
      posi = false;
    }
    if (posi) {
      if (x == 1) {
        int coord;
        char dir;
        cin >> coord >> dir;
        if (dir == 'R') {
          if (col >= coord) {
            posi = false;
          }
        }
        else { // (dir == 'L')
          if (col <= coord) {
            col = coord + 1;
          }
        }
      }
      else if (x == 2) {
        int coord1, coord2;
        char dir1, dir2;
        cin >> coord1 >> dir1 >> coord2 >> dir2;
        if (dir1 == 'R' && dir2 == 'R') {
          if (col >= coord1) {
            posi = false;
          }
        }
        else if (dir1 == 'L' && dir2 == 'L') {
          if (col <= coord2) {
            col = coord2 + 1;
          }
        }
        else if (dir1 == 'R' && dir2 == 'L') {
          if (col >= coord1 && col <= coord2) {
            col = coord2 + 1;
          }
        }
        else {  // dir1 == 'L' && dir2 == 'R'
          if (col <= coord1) { // go right first
            col = coord1 + 1;
          }
          if (col >= coord2) { // after move, check
            posi = false;
          }
        }
      }
    } 
  }
  if (col > M) {
    posi = false;
  }
  if (posi) {
    cout << "YES" << "\n";
  }
  else {
    cout << "NO" << "\n";
  }
  return 0;
}