#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	string s;
	vector<string> name;
	for (int t = 0; t < N; t++) {
		cin >> s;
		name.push_back(s);
	}
	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int len = min(name[i].size(), name[j].size());
			bool can = false;
			for (int l = 1; l <= len; l++) {
				if (name[i].substr(name[i].size() - l) == name[j].substr(0, l)) {
					can = true;
					break;
				}
				else if (name[j].substr(name[j].size() - l) == name[i].substr(0, l)) {
					can = true;
					break;
				}
			}
			if (can) {
				cnt++;
			}
		}
	}
	cout << cnt << "\n";
}