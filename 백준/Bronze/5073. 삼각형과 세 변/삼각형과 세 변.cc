#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c;
  cin >> a >> b >> c;
  while (a != 0) {
  	if (a + b <= c || b + c <= a || c + a <= b) {
			cout << "Invalid" << "\n";
	}
  	else if (a == b && b == c) {
  		cout << "Equilateral" << "\n";
	}
	else if (a == b || b == c || c == a) {
		cout << "Isosceles" << "\n";
	}
	else {
		cout << "Scalene" << "\n";
	}
  	cin >> a >> b >> c;
  }
  
  return 0;
}