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
	int N, M, K;
	cin >> N >> M >> K;
	vector<string> v;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		vector<char> c;
		for (int j = 0; j < M; j++) {
			c.push_back(s[j]);
		}
		sort(c.begin(), c.end());
		string str = "";
		for (int j = 0; j < M; j++) {
			str += c[j];
		}
		v.push_back(str);
	}
	sort(v.begin(), v.end());
	string a = "";
	for (int i = 0; i < K; i++) {
		a += v[i];
	}
	vector<char> ans;
	for (int i = 0; i < a.size(); i++) {
		ans.push_back(a[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < a.size(); i++) {
		cout << ans[i];
	}
	
	return 0;
}