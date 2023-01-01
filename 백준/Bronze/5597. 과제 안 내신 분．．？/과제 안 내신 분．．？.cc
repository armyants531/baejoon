#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<bool> arr(31);
	for (int i = 0; i < 28; i++) {
		int num;
		cin >> num;
		arr[num] = true;
	}
	for (int i = 1; i <= 30; i++) {
		if (!arr[i]) {
			cout << i << "\n";
		}
	}

	return 0;
}