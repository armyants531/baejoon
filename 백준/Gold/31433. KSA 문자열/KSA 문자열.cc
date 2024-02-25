#include <bits/stdc++.h> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	string str = "KSA";
	int idx = 0;
	int cnt = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (str[idx] == s[i]) {
			idx++;
			idx %= 3;
			cnt++;
		}
	}
	cout << 2*(n - cnt) << "\n";
	
	return 0;
}