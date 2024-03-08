#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<vector<int>> t(4001, vector<int>(4001));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (s1[i] == s2[j]) {
				t[i+1][j+1] = t[i][j] + 1;
			}
			else {
				t[i+1][j+1] = 0;
			}
		}
	}
	int max_len = 0;
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			max_len = max(max_len, t[i][j]);
		}
	}
	cout << max_len << "\n";
	
	return 0;
}