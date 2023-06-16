#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string N;
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N.size(); i++) {
		arr.push_back(N[i] - '0');
	}
	sort(arr.begin(), arr.end(), greater<int>());
	for (int i = 0; i < N.size(); i++) {
		cout << arr[i];
	}
	
	return 0;
}