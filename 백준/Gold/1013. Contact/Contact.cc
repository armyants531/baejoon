#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		bool istrue = true;
		int past = 2; // past pattern: 100+1+ or 01 (pattern 1 and 2)
		int i = 0;
		while(i < s.size()) {
			if (s[i] == '1') {
				if (i+3 < s.size() && s[i+1] == '0' && s[i+2] == '0') {
					i+=3;
					while (i < s.size() && s[i] == '0') {
						i++;
					}
					if (i < s.size() && s[i] == '1') {
						past = 1;
						i++;
					}
					else {
						istrue = false;
						break;
					}			
				}
				else if (past == 1) { // 이건 이전 신호에 속함 
					i++;
				}	
				else {
					istrue = false;
					break;
				}
			}
			else { // 0
				if (i+1 < s.size() && s[i+1] == '1') {
					i+=2;
					past = 2;
				}
				else {
					istrue = false;
					break;
				}
			}
		}
		if (istrue) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	
	return 0;
}