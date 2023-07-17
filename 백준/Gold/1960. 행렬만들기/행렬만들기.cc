// 행렬만들기
#include <bits/stdc++.h>
#define int long long

using namespace std;

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first; // 내림차순
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	//priority_queue<pair<int, int>, vector<pair<int, int>>, compare> row, col;
	int sum1 = 0;
	int sum2 = 0;
	pair<int, int> p;
	vector<pair<int, int>> col; // val, idx
	vector<pair<int, int>> row;
	for (int i = 0; i < n; i++) {
		cin >> p.first;
		p.second = i;
		sum1 += p.first;
		row.push_back(p);
	}
	for (int i = 0; i < n; i++) {
		cin >> p.first;
		p.second = i;
		sum2 += p.first;
		col.push_back(p);
	}
	if (sum1 == sum2) {
		bool can = true;
		vector<vector<int>> a(n, vector<int>(n));
		sort(row.begin(), row.end(), greater<pair<int, int>>());
		for (int i = 0; i < n; i++) {
			if (!can) break;
			pair<int, int> r = row[i];
			int cnt = 0;
			sort(col.begin(), col.end(), greater<pair<int, int>>());
			for (int j = 0; j < n; j++) {
				if (col[j].first != 0) {
					col[j].first--;
					a[r.second][col[j].second] = 1;
					cnt++;
				}
				if (cnt == r.first) break;
			}
			if (cnt != r.first) {
				//cout << "i: " << i << "\n";
				can = false;
				break;
			}
		}
		if (can) {
			cout << 1 << "\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << a[i][j];
				}
				cout << "\n";
			}
		}
		else {
			cout << -1 << "\n";
		}
		
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}