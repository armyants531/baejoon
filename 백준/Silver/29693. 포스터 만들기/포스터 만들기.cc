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
	int Y, X;
	cin >> Y >> X;
	vector<string> a;
	for (int i = 0; i < Y; i++) {
		string s;
		cin >> s;
		a.push_back(s);
	}
	bool can = false;
	int idx = 0;
	if (X % 2) { // 가운데 3칸 필요 
		if (X >= 5) {
			for (int i = 0; i < Y; i++) {
				if (a[i].substr(X / 2 - 1, 3) == "XXX") {
					can = true;
					idx = i;
					break;
				}
			}	
		}
	}
	else { // 가운데 4칸 필요 
		if (X >= 6) {
			for (int i = 0; i < Y; i++) {
				if (a[i].substr(X / 2 - 2, 4) == "XXXX") {
					can = true;
					idx = i;
					break;
				}
			}	
		}
	}
	if (can) {
		cout << "YES" << "\n";
		if (X % 2) {
			for (int i = 0; i < Y; i++)	{
				if (i != idx) {
					for (int j = 0; j < X; j++) {
						cout << 'B';
					}
				}
				else {
					for (int j = 0; j < X / 2 - 1; j++) {
						cout << 'B';
					}
					cout << "WYW";
					for (int j = X / 2 + 2; j < X; j++) {
						cout << 'B';
					}
				}
				cout << "\n";		
			}
		}
		else {
			for (int i = 0; i < Y; i++)	{
				if (i != idx) {
					for (int j = 0; j < X; j++) {
						cout << 'B';
					}
				}
				else {
					for (int j = 0; j < X / 2 - 2; j++) {
						cout << 'B';
					}
					cout << "WYYW";
					for (int j = X / 2 + 2; j < X; j++) {
						cout << 'B';
					}
				}
				cout << "\n";		
			}
		}
	}
	else {
		cout << "NO" << "\n";
	}
	return 0;
}