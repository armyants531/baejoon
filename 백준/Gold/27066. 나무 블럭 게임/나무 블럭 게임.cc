// 나무 블럭 게임  // greedy  // ad-hoc
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<double> arr;
	vector<double> arr2;
	for (int i = 0; i < n; i++) {
		double a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
	cout << fixed;
	cout.precision(12);
	if (n == 1) {
		cout << arr[0];
	}
	else {
		double sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
		}
		cout << max(arr[n - 2], sum / n);
	}

	return 0;
}