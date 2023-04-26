#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int min_x = 100001;
	int min_y = 100001;
	int max_x = -100001;
	int max_y = -100001;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		max_x = max(max_x, x);
		min_x = min(min_x, x);
		max_y = max(max_y, y);
		min_y = min(min_y, y);
	}
	cout << (max_x - min_x) * (max_y - min_y) << "\n";
	
	return 0;	
}