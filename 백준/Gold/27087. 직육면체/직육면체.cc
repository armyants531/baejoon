// 직육면체  // number theory
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int A, B, C, p;
    cin >> A >> B >> C >> p;
    if (A % p == 0 && B % p == 0 || B % p == 0 && C % p == 0 || C % p == 0 && A % p == 0) {
      cout << 1 << "\n";
    }
    else {
      cout << 0 << "\n";
    }
  }
  
	return 0;
}