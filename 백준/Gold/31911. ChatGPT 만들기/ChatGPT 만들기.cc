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
	mx[27] = -1; // for ']': after ']', only '.' can be appeared
	vector<bool> visited(30);
	string ans = "[";
	char start; // start of repeated string
	int i = 0;
	for (; i < K + M - 1; i++) {
		int cur;
		if (i >= K-1) {
			//cout << ans[i];
		}
		if ('a' <= ans[i] && ans[i] <= 'z') {
			cur = ans[i] - 'a';
			if (visited[cur]) {
				start = ans[i];
				break; 
			}
			visited[cur] = true;
		}
		else if (ans[i] == '[') {	
			cur = 26;
			if (visited[cur]) {
				start = ans[i];
				break;
			}
			visited[cur] = true;
		}
		else if (ans[i] == ']') {
			cur = 27;
			if (visited[cur]) {
				start = ans[i];
				break;
			}
			visited[cur] = true;
		}
		else if (ans[i] == '-') {
			cur = 28;
			if (visited[cur]) {
				start = ans[i];
				break;
			}
			visited[cur] = true;
		}
		else { // ans[i] == '.'
			cur = -1;
			if (visited[29]) {
				start = ans[i];
				break;
			}
			visited[29] = true;
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
			else {  // next == -1
				ans += '.';
			}
		}
	}
	//cout << ans << "\n";
	string rep = "";
	int rep_idx;
	for (int i = ans.size() - 2; i >= 0; i--) {
		if (ans[i] == start) {
			rep = ans[i] + rep;
			rep_idx = i;
			break;
		}
		else {
			rep = ans[i] + rep;
		}
	}
	if (rep_idx > K + M - 2) {
		cout << ans.substr(K-1, M) << "\n";
	}
	else if (rep_idx > K - 1) {
		cout << ans.substr(K-1, rep_idx - (K-1));
		for (int i = 0; i < M - (rep_idx - (K-1)); i++) {
			cout << rep[i % rep.size()];	
		}
	}
	else {  // rep_idx <= K - 1
		for (int i = K - 2 - rep_idx + 1; i < K - 2 - rep_idx + 1 + M; i++) {
			cout << rep[i % rep.size()];	
		}
	}
	
	return 0;
}