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
		vector<bool> vec(780); // 60 ~ 779 minute
		for (int i = 0; i < M; i++) {
			int t = v[i] - r * i;
			while (t < 60) {
				t += 720;
			}
			vec[t] = true;
		}
		int l = 0;
		for (int i = 60; i < 780; i++) {
			if (vec[i]) {
				l++;
			}
		}
		min_n = min(min_n, l);
	}
	cout << min_n << "\n";
	
	return 0;
}