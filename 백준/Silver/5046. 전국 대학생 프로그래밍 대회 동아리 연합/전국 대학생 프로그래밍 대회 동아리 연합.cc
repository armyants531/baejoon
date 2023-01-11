// Event Planning  // implementation
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int N, B, H, W;
	cin >> N >> B >> H >> W; 
  int min_cost = B + 1;
  for (int i = 0; i < H; i++) {
    int p;
    cin >> p;
    int cost = p * N;
    for (int j = 0; j < W; j++) {
      int a;
      cin >> a;
      if (cost > B) {
        continue;
      }
      if (N <= a) {
        min_cost = min(min_cost, cost);
      }
    }
  }  
  if (min_cost > B) {
    cout << "stay home" << "\n";
  }  
  else {
    cout << min_cost << "\n";
  }
	return 0;
}