#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> arr;
vector<int> id_cnt(26);
vector<int> cnt(26);
bool visited[50][50];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, len;
	cin >> N >> M >> len;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		arr.push_back(s);
	}
	string id;
	cin >> id;
	for (int i = 0; i < id.size(); i++) {
		id_cnt[id[i] - 'a']++;
	}
	vector<queue<pair<int, int>>> point(26);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cnt[arr[i][j] - 'a']++;
			if (id_cnt[arr[i][j] - 'a'] > 0) {
				point[arr[i][j] - 'a'].push({ i, j });
			}
		}
	}
	/*
	for (int i = 0; i < 26; i++) {
		cout << (char)('a' + i) << " ";
		while (!point[i].empty()) {
			cout << "{ " << point[i].front().first << ", " << point[i].front().second << " } ";
			point[i].pop();
		}
		cout << "\n";
	}
	*/
	int max_c = 2501;
	for (int i = 0; i < id.size(); i++) {
		if (id_cnt[id[i] - 'a'] != 0) {
			max_c = min(max_c, cnt[id[i] - 'a'] / id_cnt[id[i] - 'a']);
		}
	}
	//cout << max_c << "\n";

	string ans = "";
	int idx = 0;
	int x = 0;
	int y = 0;
	string tot = ""; // id * max_c;
	for (int i = 0; i < max_c; i++) {
		tot += id;
	}
	
	for (int i = 0; i < tot.size(); i++) {
		int nx = point[tot[i] - 'a'].front().first;
		int ny = point[tot[i] - 'a'].front().second;
		point[tot[i] - 'a'].pop();
		if (nx - x > 0) {
			for (int k = 0; k < nx - x; k++) {
				ans += 'D';
			}
		}
		else {
			for (int k = 0; k < x - nx; k++) {
				ans += 'U';
			}
		}
		if (ny - y > 0) {
			for (int k = 0; k < ny - y; k++) {
				ans += 'R';
			}
		}
		else {
			for (int k = 0; k < y - ny; k++) {
				ans += 'L';
			}
		}
		ans += 'P';
		x = nx;
		y = ny;
	}
	for (int i = x; i < N - 1; i++) {
		ans += 'D';
	}
	for (int i = y; i < M - 1; i++) {
		ans += 'R';
	}
	cout << max_c << " " << ans.size() << "\n";
	cout << ans << "\n";
	
	return 0;
}