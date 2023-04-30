// 인사성 밝은 곰곰이  // map
#include <bits/stdc++.h>

using namespace std;

map<string, bool> mp;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n, cnt = 0;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "ENTER") {
			mp.erase(mp.begin(), mp.end());
		}
		else if (!mp[s]) {
			mp[s] = true;
			cnt++;	
		}
	}
	cout << cnt << "\n";

	return 0;
}