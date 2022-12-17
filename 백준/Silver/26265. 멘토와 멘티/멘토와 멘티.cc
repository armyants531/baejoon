#include <bits/stdc++.h>

using namespace std;

bool compare(pair<string, string> a, pair<string, string> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<string, string>> arr;
	for (int i = 0; i < N; i++) {
		string A, B;
		cin >> A >> B;
		arr.push_back({A, B});
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}

	return 0;
}