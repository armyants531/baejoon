#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tot = 0;
	for (int i = 0; i < 4; i++) {
		int t;
		cin >> t;
		tot += t;
	}
	cout << tot / 60 << "\n" << tot % 60 << "\n";
	
	return 0;
}