#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	string s;
	string ans;
	cin >> s;
	while (!s.empty()) {
		if (s.back() == 'A' && s.back() == 'E' && s.back() == 'I' && s.back() == 'O' && s.back() == 'U') {
			s.pop_back();
		}
		else {
			break;
		}
	}
	ans.push_back(s.back());
	s.pop_back();
	if (s.size() >= 2) {
		int cnt = 0;
		while (!s.empty()) {
			if (s.back() == 'A') {
				cnt++;
				s.pop_back();
				if (cnt == 2) {
					break;
				}
			}
			else {
				s.pop_back();
			}
		}
		if (cnt == 2 && s.size() >= M - 3) {
			cout << "YES" << "\n";
			ans.push_back('A');
			ans.push_back('A');
			for (int i = M - 4; i >= 0; i--) {
				ans.push_back(s[i]);
			}
			reverse(ans.begin(), ans.end());
			cout << ans;
		}
		else {
			cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
}