#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int R, C;
		cin >> R >> C;
		vector<string> arr;
		int min_x = 11;
		int min_y = 11;
		int max_x = 0;
		int max_y = 0;
		int cnt = 0;  // #의 개수
		for (int i = 0; i < R; i++) {
			string s;
			cin >> s;
			arr.push_back(s);
			for (int j = 0; j < C; j++) {
				if (s[j] == '#') {
					cnt++;
					if (min_x > i) {
						min_x = i;
					}
					if (min_y > j) {
						min_y = j;
					}
					if (max_x < i) {
						max_x = i;
					}
					if (max_y < j) {
						max_y = j;
					}
				}
			}
		}
		// cout << cnt << "\n";
		int N;
		int len1 = max_x - min_x + 1;
		int len2 = max_y - min_y + 1;
		if (len1 == len2) {
			N = len1;
			int N2 = N * N;
			bool check_cnt = false;
			int M;
			for (M = 1; M < N; M++) {
				if (cnt == N2 - M * M) { // #의 개수가 N^2 - M^2 인가?
					check_cnt = true;
					break;
				}
			}
			if (check_cnt) {
				// 4개의 꼭짓점에 대해 M * M 칸에 #이 없는가?
				bool isCorrect = true;
				for (int i = min_x; i < min_x + M; i++) {
					for (int j = min_y; j < min_y + M; j++) {
						if (arr[i][j] == '#') {
							isCorrect = false;
							break;
						}
					}
					if (!isCorrect) break;
				}
				if (isCorrect) {
					cout << 1 << "\n";
				}
				else {
					isCorrect = true;
					for (int i = min_x; i < min_x + M; i++) {
						for (int j = max_y; j > max_y - M; j--) {
							if (arr[i][j] == '#') {
								isCorrect = false;
								break;
							}
						}
						if (!isCorrect) break;
					}
					if (isCorrect) {
						cout << 1 << "\n";
					}
					else {
						isCorrect = true;
						for (int i = max_x; i > max_x - M; i--) {
							for (int j = min_y; j < min_y + M; j++) {
								if (arr[i][j] == '#') {
									isCorrect = false;
									break;
								}
							}
							if (!isCorrect) break;
						}
						if (isCorrect) {
							cout << 1 << "\n";
						}
						else {
							isCorrect = true;
							for (int i = max_x; i > max_x - M; i--) {
								for (int j = max_y; j > max_y - M; j--) {
									if (arr[i][j] == '#') {
										isCorrect = false;
										break;
									}
								}
								if (!isCorrect) break;
							}
							if (isCorrect) {
								cout << 1 << "\n";
							}
							else {
								cout << 0 << "\n";
							}
						}
					}
				}	
			}
			else {
				cout << 0 << "\n";
			}
		}
		else {
			cout << 0 << "\n";
		}
	}

	return 0;
}