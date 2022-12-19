// 명제 증명  // Floyd-Warshall
#include <bits/stdc++.h>

using namespace std;

int INF = 100000000;
vector<vector<int>> adj(52, vector<int>(52, INF));
vector<vector<int>> ans(52, vector<int>(52));

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char x, y;
		string s;
		cin >> x;
		cin >> s;
		cin >> y;
		int X = x;
		if (X <= 90) { // 대문자이면
			X -= 65;
		}
		else { // 소문자이면
			X -= 71; // - 97 + 26
		}
		int Y = y;
		if (Y <= 90) { // 대문자이면
			Y -= 65;
		}
		else { // 소문자이면
			Y -= 71; // - 97 + 26
		}
		adj[X][Y] = 1;
	}

	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			ans[i][j] = adj[i][j];
		}
	}
	// 플로이드-워셜
	for (int k = 0; k < 52; k++) {
		for (int i = 0; i < 52; i++) {
			for (int j = 0; j < 52; j++) {
				if (ans[i][k] + ans[k][j] < ans[i][j]) {
					ans[i][j] = ans[i][k] + ans[k][j];
				}
			}
		}
	}
	// 증명 가능한 명제 찾고 출력
	int cnt = 0;
	vector<pair<char, char>> proposition;
	for (int i = 0; i < 52; i++) {
		for (int j = 0; j < 52; j++) {
			if (ans[i][j] != INF && i != j) {
				cnt++;
				char x, y;
				if (i < 26) {
					x = i + 'A';
				}
				else {
					x = i - 26 + 'a';
				}

				if (j < 26) {
					y = j + 'A';
				}
				else {
					y = j - 26 + 'a';
				}
				proposition.push_back({x, y});
			}
		}
	}
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		cout << proposition[i].first << " => " << proposition[i].second << "\n";
	}

	return 0;
}