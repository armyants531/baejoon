#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int H;
		cin >> H;
		arr.push_back(H);
	}
	int len = 0;
	for (int i = 0; i < N - 1; i++) {
		len += (arr[i] - arr[i + 1]) * (arr[i] - arr[i + 1]) + (arr[i] + arr[i + 1]) * (arr[i] + arr[i + 1]);
	}
	cout << len << "\n";
	return 0;
}