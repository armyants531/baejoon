// Wordle 찍기  
#include <bits/stdc++.h>
#define int long long

using namespace std;

char a[5] = { 'A', 'B', 'C', 'D', 'E' };

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	string s;
	bool posi = true;
	vector<vector<char>> str(N, vector<char>(5));
	vector<int> cntG(N);
	vector<int> cntY(N);
	for (int i = 0; i < N; i++) {
		cin >> s;
		vector<int> gray;
		vector<int> yellow;
		cntG[i] = 0;
		cntY[i] = 0;
		for (int j = 0; j < 5; j++) {
			if (s[j] == 'G') {
				cntG[i]++;
			}
			else if (s[j] == 'Y') {
				cntY[i]++;
				yellow.push_back(j);
			}
			else { // 'B'
				gray.push_back(j);
			}
		}
		if (cntG[i] == 4 && cntY[i] == 1) {
			posi = false;
		}
		else if (cntY[i] == 1) { // 'B'자리의 숫자 아무거나 'Y'자리에 쓰기
			for (int j = 0; j < 5; j++) {
				if (s[j] == 'B') {
					str[i][j] = 'F';
				}
				else if (s[j] == 'G') {
					str[i][j] = a[j];
				}
				else { // s[j] == 'Y'
					str[i][j] = a[gray[0]];
				}
			}
		}
		else { // cntY[i] >= 2, 'Y'자리끼리 교환
			int y_idx = 0; // Y idx
			for (int j = 0; j < 5; j++) {
				if (s[j] == 'B') {
					str[i][j] = 'F';
				}
				else if (s[j] == 'G') {
					str[i][j] = a[j];
				}
				else { // s[j] == 'Y'
					str[i][j] = a[yellow[(y_idx + 1) % cntY[i]]];
					y_idx++;
				}
			}
		}
	}
	if (posi) {
		cout << "ABCDE" << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 5; j++) {
				cout << str[i][j];
			}
			cout << "\n";
		}
	}
	else {
		cout << "IMPOSSIBLE" << "\n";
	}
	return 0;
}