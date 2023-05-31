// 현대모비스 특별상의 주인공은?  // ad-hoc
// oo 또는 oxo 형태가 존재하는가?
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<string>> arr(N, vector<string>(M));
	set<string> s;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			s.insert(arr[i][j]);
		}
	}
	map<string, bool> mp;
	// 1. oo 형태 검사
	// 가로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				mp[arr[i][j]] = true;
			}
		}
	}
	// 세로
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == arr[i + 1][j]) {
				mp[arr[i][j]] = true;
			}
		}
	}
	// 2. oxo 형태 검사
	// 가로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (arr[i][j] == arr[i][j + 2]) {
				mp[arr[i][j]] = true;
			}
		}
	}
	// 세로
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == arr[i + 2][j]) {
				mp[arr[i][j]] = true;
			}
		}
	}
	// 선물을 받을 수 있는 이름 구하기
	set<string> present;
	for (std::set<string>::iterator it = s.begin(); it != s.end(); it++) {
		if (mp[*it]) {
			present.insert(*it);
		}
	}
	if (present.size() == 0) {
		cout << "MANIPULATED" << "\n";
	}
	else {
		for (std::set<string>::iterator it = present.begin(); it != present.end(); it++) {
			cout << *it << "\n";
		}
	}

	return 0;
}