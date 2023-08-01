// 최소 회의실 개수 
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
using pii = pair<int, int>;
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pii> arr;
	int x, y;
	set<int> s;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		s.insert(x);
		s.insert(y);
		arr.push_back({x, 1});
		arr.push_back({y, -1});
	}
	sort(arr.begin(), arr.end());
	int ans = 0;
	int idx = 0;
	int pre = 0;
	for (auto t : s) {
		while (idx < arr.size() && t >= arr[idx].first) {
			pre += arr[idx].second;
			idx++;
		}
		ans = max(ans, pre);
	}
	
	cout << ans << "\n";
 
	return 0;
}