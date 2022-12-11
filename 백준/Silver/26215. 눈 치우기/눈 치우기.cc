#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), greater<int>());
	int ans = 0;
	if (N == 1) {
		ans = arr[0];
	}
	else {
		while (arr.size() >= 2) {
			ans += arr[1];
			arr[0] -= arr[1];
			arr.erase(arr.begin() + 1);
			sort(arr.begin(), arr.end(), greater<int>());
		}	
		ans += arr[0];
	}

	if (ans > 1440) {
		cout << -1 << "\n";
	}
	else {
		cout << ans << "\n";
	}

	return 0;
}