#include <bits/stdc++.h> 

using namespace std;
vector<int> s;
int k;

void rec(int idx, int cnt, vector<int> v) {
	//cout << idx << " " << cnt << "\n";
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	else if (idx == k) return;
	vector<int> v2;
	if (cnt != 0) {
		for (int i = 0; i < v.size(); i++) {
			v2.push_back(v[i]);
		}
	}
	v2.push_back(s[idx]);
	rec(idx + 1, cnt + 1, v2);
	rec(idx + 1, cnt, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> k;
		if (k == 0) {
			break;
		}
		s.clear();
		s.resize(k);
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		vector<int> v;
		rec(0, 0, v);
		cout << "\n";
	}

	return 0;
}