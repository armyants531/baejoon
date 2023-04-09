#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<vector<char>> arr(5, vector<char>(15, '+'));
	string s;
	int max_len = 0;
	for (int i = 0; i < 5; i++) {
		cin >> s;
		max_len = max(max_len, (int)s.size());
		for (int j = 0; j < s.size(); j++) {
			arr[i][j] = s[j];
		}
	}
	for (int i = 0; i < max_len; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] == '+') continue;
			cout << arr[j][i];  
		}
	}
	
	return 0;
}