#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M;
	cin >> M;
	vector<int> v(M);
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		string h = s.substr(0, 2);
		string m = s.substr(3, 2);
		int time = stoi(h) * 60 + stoi(m);
		v[i] = time;
	}
	int min_n = M;
	for (int r = 1; r <= 720; r++) {
		unordered_set<int> st;
		for (int i = 0; i < M; i++) {
			int t = v[i] - r * i;
			while (t < 60) {
				t += 720;
			}
			st.insert(t);
		}
		int l = st.size();
		min_n = min(min_n, l);
	}
	cout << min_n << "\n";
	
	return 0;
}