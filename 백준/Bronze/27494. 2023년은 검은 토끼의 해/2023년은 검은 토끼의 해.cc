#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int cnt = 0;
	vector<char> arr = { '2', '0', '2', '3' };
	for (int i = 2023; i <= N; i++) {
		int k = 0;
		bool suc = false;
		string s = to_string(i);
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == arr[k]) {
				k++;
				if (k == 4) {
					suc = true;
					break;
				}
			}
		}
		if (suc) {
			cnt++;
		}
	}
	cout << cnt;
}