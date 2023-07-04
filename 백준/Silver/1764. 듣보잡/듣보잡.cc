#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<string, bool> mp; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		mp[s] = true;
	}
	vector<string> arr;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (mp[s]) {
			arr.push_back(s);
		}
	}
	sort(arr.begin(), arr.end());
	cout << arr.size() << "\n";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << "\n";
	}
	
	return 0;	
}