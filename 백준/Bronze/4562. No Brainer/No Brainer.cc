#include <bits/stdc++.h>

using namespace std;

vector<string> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x >= y) {
			cout << "MMM BRAINS" << "\n";
		}
		else {
			cout << "NO BRAINS" << "\n";
		}
	}
	
	return 0;
}