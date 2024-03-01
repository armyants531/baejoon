#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int l = 301;
	int r = 1130;
	vector<pair<int, int>> t;
	for (int i = 0; i < n; i++) {
		int t1, t2, a, b, c, d;
		cin >> a >> b >> c >> d;
		t1 = 100 * a + b;
		t2 = 100 * c + d - 1;
		if (t2 >= l && t1 <= r) {
			t.push_back({t1, t2});
		}
	}
	if (t.size() == 0) {
		cout << 0 << "\n";
		return 0;
	}
	sort(t.begin(), t.end());
	int end = t[0].second;
	int prepre_l = 0;
	int prepre_r = l-1;
	int pre_l = t[0].first;
	int pre_r = t[0].second;
	int cnt = 1;
	bool can = false;
	if (pre_r >= r && pre_l <= l) {
		can = true;
	}
	else if (l < pre_l) {
		cout << 0 << "\n";
		return 0;
	}
	else {
		for (int i = 1; i < t.size(); i++) {
			if (prepre_r + 1 >= t[i].first && pre_r <= t[i].second) {
				// 이전 꽃 버림, 현재 꽃 추가  
				pre_l = t[i].first;
				pre_r = t[i].second;
			}
			else if (pre_r + 1 >= t[i].first && pre_r < t[i].second) {
				// 현재 꽃 추가  
				cnt++;
				prepre_l = pre_l;
				prepre_r = pre_r; 
				pre_l = t[i].first;
				pre_r = t[i].second;
			}
			if (pre_r >= r) {
				can = true;
				break;
			}
		}
	}
	if (can) cout << cnt << "\n";
	else cout << 0 << "\n";

	return 0;
}