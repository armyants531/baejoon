#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, n;
	cin >> T >> n;
	int F;
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> F; 
		s += F;
	}
	if (s >= T) {
		cout << "Padaeng_i Happy" << "\n";
	}
	else {
		cout << "Padaeng_i Cry" << "\n";
	}
	
	return 0;
}