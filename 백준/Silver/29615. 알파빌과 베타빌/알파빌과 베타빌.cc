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
	int N, M;
	cin >> N >> M;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	map<int, bool> mp; // is friend?
	int b;
	for (int i = 0; i < M; i++) { 
		cin >> b;
		mp[b] = true;
	}
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (!mp[a[i]]) {
			cnt++;
		}
	}
	cout << cnt << "\n";
	
	return 0;
}