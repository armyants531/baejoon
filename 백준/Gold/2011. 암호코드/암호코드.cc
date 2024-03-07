#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
string s;
vector<int> t(5001);

int dp(int idx) {
	if (idx == s.size()) {
		return 1;
	} 
	if (s[idx] == '0') {
		return 0;
	}
	if (t[idx] != 0) {
		return t[idx];
	}
	if (s[idx] == '1') {
		t[idx] = dp(idx+1);
		t[idx] %= 1000000;
		if (idx + 2 <= s.size())
		t[idx] += dp(idx + 2);
		t[idx] %= 1000000;
	}
	else if (s[idx] == '2') {
		t[idx] = dp(idx+1);
		t[idx] %= 1000000;
		if (idx + 2 <= s.size() && s[idx+1] >= '0' && s[idx+1] <= '6')
		t[idx] += dp(idx + 2);
		t[idx] %= 1000000;
	}
	else {
		t[idx] = dp(idx + 1);
		t[idx] %= 1000000;
	}
	return t[idx];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	cout << dp(0) << "\n";
	return 0;
}