// Phone List  // string  // sort
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		map<string, bool> mp;
		bool isConsistent = true;
		vector<string> strArr;
		for (int j = 0; j < N; j++) {
			string str;
			cin >> str;
			strArr.push_back(str);
		}
		sort(strArr.begin(), strArr.end()); // 앞자리 숫자에 대해 오름차순

		for (int j = 0; j < N; j++) {
			string str = strArr[j];
			string s = "";
			// 97625999의 경우: 9 -> 97 -> 976 -> 9762 -> ... -> 9762599
			for (int k = 0; k < str.length() - 1; k++) {
				s += str[k]; 
				if (mp[s] == true) { // s가 이미 있는 번호이면
					isConsistent = false;
					break;
				}
			}
			mp[str] = true; // mp에 번호 str 저장
			if (!isConsistent) {
				break;
			}
		}
		if (isConsistent) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}