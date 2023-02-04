#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	vector<int> ans(26, -1);
	for (int i = 0; i < s.size(); i++) {
		int idx = s[i] - 'a';
		if (ans[idx] == -1) {
			ans[idx] = i;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}