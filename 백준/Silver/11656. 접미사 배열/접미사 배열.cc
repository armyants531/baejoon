#include <bits/stdc++.h> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<string> v;
	for (int i = 0; i < n; i++) {
		v.push_back(s.substr(i, n - i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
	return 0;
}