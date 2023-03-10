#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (n != 0) {
		if (m % n == 0) cout << "factor" << "\n";
		else if (n % m == 0) cout << "multiple" << "\n";
		else cout << "neither" << "\n";
		cin >> n >> m;
	}
	
	return 0;
}