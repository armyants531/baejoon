#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> arr;
	int n;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		arr.push_back(n);
		sum += n;
	}
	sort(arr.begin(), arr.end());
	cout << sum / 5 << "\n";
	cout << arr[2] << "\n";
}