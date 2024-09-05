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
	int N, K, M;
	cin >> N >> K >> M;
	// 26: [, 27: ], 28: - 
	vector<vector<int>> v(29, vector<int>(29));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int n = s.size(); 
		for (int j = 1; j < n; j++) {
			if ('a' <= s[j-1] && s[j-1] <= 'z') {
				if ('a' <= s[j] && s[j] <= 'z') {
					v[s[j-1] - 'a'][s[j] - 'a']++;
				}
				else if (s[j] == ']') {
					v[s[j-1] - 'a'][27]++;
				}
				else { // s[j] == '-'
					v[s[j-1] - 'a'][28]++;
				}	
			}
			else if (s[j-1] == '[') {
				if ('a' <= s[j] && s[j] <= 'z') {
					v[26][s[j] - 'a']++;
				}
				else { // s[j] == '-'
					v[26][28]++;
				}	
			}
			else { // s[j-1] == '-'
				if ('a' <= s[j] && s[j] <= 'z') {
					v[28][s[j] - 'a']++;
				}
				else if (s[j] == ']') {
					v[28][27]++;
				}
				else { // s[j] == '-'
					v[28][28]++;
				}	
			}
		}
	}
	vector<int> mx(29);
	for (int i = 0; i < 29; i++) {
		int mx_idx = -1;
		int mx_val = 0;
		// ascii code  
		if (mx_val < v[i][28]) {  // - 
			mx_val = v[i][28];
			mx_idx = 28;
		}
		if (mx_val < v[i][27]) {  // ]
			mx_val = v[i][27];
			mx_idx = 27;
		}
		for (int j = 0; j < 26; j++) {
			if (mx_val < v[i][j]) {
				mx_val = v[i][j];
				mx_idx = j;
			}
		}
		mx[i] = mx_idx;
	}
	//cout << v['s' - 'a'][27] << "\n";
	//cout << v['s' - 'a'][19] << "\n";
	//cout << mx['s' - 'a'] << "\n";
	mx[27] = -1; // for '.': after '.', only '.' can be appeared
	string ans = "[";
	for (int i = 0; i < K + M - 1; i++) {
		int cur;
		if ('a' <= ans[i] && ans[i] <= 'z') {
			cur = ans[i] - 'a';
		}
		else if (ans[i] == '[') {	
			cur = 26;
		}
		else if (ans[i] == ']') {
			cur = 27;
		}
		else if (ans[i] == '-') {
			cur = 28;
		}
		else { // ans[i] == '.'
			cur = -1;
		}
		if (cur == -1) {
			ans += '.';
		}
		else {
			int next = mx[cur];
			if (0 <= next && next <= 25) {
				ans += (next + 'a');
			}
			else if (next == 27) {
				ans += ']';
			}
			else if (next == 28) {
				ans += '-';
			}	
		}
	}
	for (int i = K - 1; i < K + M - 1; i++) {
		cout << ans[i];
	}
	
	return 0;
}