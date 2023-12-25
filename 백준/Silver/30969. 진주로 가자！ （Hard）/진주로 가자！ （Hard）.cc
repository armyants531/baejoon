#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	string D;
	int C;
	short cost;
	bool check = false;
	vector<short> c;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cin >> D >> C;
		if (C > 1000) {
			cnt++;
		}
		else {
			if (D == "jinju") {
				cost = C;
				check = true;
			}
			else {
				if (check){
					if (cost < C) {
						cnt++;
					}
				} 
				else {
					c.push_back(C);
				}				
			}
		}
	}
	for (int i = 0; i < c.size(); i++) {
		if (cost < c[i]) {
			cnt++;
		}
	}
	cout << cost << "\n";
	cout << cnt << "\n";
	
	return 0;
}