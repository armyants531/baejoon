#include <bits/stdc++.h> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	unordered_map<string, int> mp1;
	vector<vector<string>> v(N);
	unordered_map<string, string> mp2;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		mp1[s] = i; // 팀 id 지정 
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			string name;
			cin >> name;
			v[i].push_back(name);
			mp2[name] = s;
		}
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		int tp;
		cin >> tp;
		if (tp == 0) {
			for (auto mem : v[mp1[s]]) {
				cout << mem << "\n";
			}
		}
		else {
			cout << mp2[s] << "\n";
		}
	}
	return 0;
}