#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  int up = 0;
  int down = 0;
  int up_down = 0;
  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
  	cin >> arr[i];
  	if (arr[i] == 1) {
  		up++;		
	}
	else if (arr[i] == 2) {
		down++;
	}
	else { // arr[i] == 3
		up_down++;
	}
  } 
  int U, D;
  cin >> U >> D;
  int need_up = U - up;
  int need_down = D - down;
  if (need_up > up_down || need_down > up_down) {
  	cout << "NO" << "\n";
  }
  else {
  	cout << "YES" << "\n";
  	for (int i = 0; i < N; i++) {
		if (arr[i] == 1) {
			cout << "U";
		}
		else if (arr[i] == 2) {
			cout << "D";
		}
		else {
			if (need_up > 0) {
				need_up--;
				cout << "U";
			}
			else {
				cout << "D";
			}	
		}
	}	
  }
  
  return 0;
}