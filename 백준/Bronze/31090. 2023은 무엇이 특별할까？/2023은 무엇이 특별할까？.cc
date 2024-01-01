#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		string e = s.substr(2, 2);
		int end = stoi(e);
		int nex = stoi(s);
		nex++;
		//cout << nex << " " << end << "\n";
		if (nex % end == 0) {
			cout << "Good" << "\n";
		} 
		else {
			cout << "Bye" << "\n";
		}
	}
	return 0;
}