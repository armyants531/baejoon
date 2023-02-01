#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
 
int main() { 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x; // x = 1 + 2 + ... + N + a
	cin >> x;
	int i = 1;
	while (x > i) {
		x -= i;
		i++;
	}
	// 주어진 x는 i번째 묶음에 속함(i = N + 1, x = a or i = N, x = N)  
 	int up, down;
	if (i % 2 == 1) {
 		up = i + 1 - x;
 		down = x;
	}
	else { // i % 2 == 0
		down = i + 1 - x;
		up = x;
	}
 	cout << up << '/' << down << "\n";
 	
    return 0;
}
