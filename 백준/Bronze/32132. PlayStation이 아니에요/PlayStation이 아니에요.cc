#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int N;
	cin >> N;
	string s;
	cin >> s;
	string ans = "";
	string temp = "";
	for (int i = 0; i < N; i++) {
		if (temp.size() == 0) {
			if (s[i] == 'P') {
				temp += s[i];
			}
			else {
				ans += s[i];
			}	
		}
		else if (temp.size() == 1) {
			if (s[i] == 'S') {
				temp += s[i];
			}
			else if (s[i] == 'P') { // attention!  // PPS456 -> PPS6
				ans += temp;
				temp = s[i];
			}
			else {
				ans += (temp + s[i]);
				temp = "";
			}
		}
		else if (temp.size() == 2) {
			if (s[i] == '4' || s[i] == '5') {
				continue;
			}
			else if (s[i] == 'P') {  // attention!
				ans += temp;
				temp = s[i];
			}
			else {
				ans += (temp + s[i]);
				temp = "";
			}
		}
	}
	ans += temp;
	cout << ans << "\n";
	return 0;
}