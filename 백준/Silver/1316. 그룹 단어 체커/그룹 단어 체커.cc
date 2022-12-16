// 그룹 단어 체커  // 문자열
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		vector<int> arr(26, 0);
		char c = str[0];
		bool isGroup = true;
		int idx_c = (int)(c - 'a');
		arr[idx_c]++;
		for (int j = 1; j < str.length(); j++) {
			if (str[j] != c) { // 이전 문자와 다른 문자이면
				int idx = (int)(str[j] - 'a');
				arr[idx]++;
				c = str[j];
				if (arr[idx] == 2) {
					isGroup = false;
					break;
				}
			}
		}
		if (isGroup) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}