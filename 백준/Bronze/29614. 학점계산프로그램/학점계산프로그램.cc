#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	double tot = 0;
	double n = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			tot += 4;
			n++;
		}
		else if (s[i] == 'B') {
			tot += 3;
			n++;
		}
		else if (s[i] == 'C') {
			tot += 2;
			n++;
		}
		else if (s[i] == 'D') {
			tot++;
			n++;
		}
		else if (s[i] == 'F') {
			n++;
		}
		else { // +
			tot += 0.5;
		}
	}
	cout << tot / n << "\n";
	
	return 0;
}