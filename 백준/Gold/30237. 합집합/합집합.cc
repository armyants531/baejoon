#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<map<int, bool>> mp(n);
		vector<vector<int>> v(n);
		int k;
		set<int> num;
		for (int i = 0; i < n; i++) {
			cin >> k;
			for (int j = 0; j < k; j++) {
				int s;
				cin >> s;
				mp[i][s] = true;
				v[i].push_back(s);
				num.insert(s);
			}
		}
		int max_s = 0;
		for (auto i : num) {
			set<int> s;
			for (int j = 0; j < n; j++) {
				if (!mp[j][i]) {
					for (int k = 0; k < v[j].size(); k++) {
						s.insert(v[j][k]);
					}
				}
			}
			if (s.size() > max_s) {
				max_s = s.size();
			}
		}
		
		cout << max_s << "\n";
	}

	
	return 0;
}