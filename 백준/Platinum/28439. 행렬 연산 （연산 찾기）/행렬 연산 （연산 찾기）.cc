// 행렬 연산 (연산 찾기) 
// 1행에 +x 를 한다고 생각, 그럼 c열에는 A[1][c] - x를 더해야 함
// 이때 r행에 더하는 수는 A[r][1] - (A[1][1] - x) = x - (A[1][1] - A[r][1])
// x를 모든 A[1][c], A[1][1] - A[r][1]값 중 가장 많은 것으로 정하자!
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> A(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	map<int, int> cnt;
	for (int i = 1; i <= M; i++) {
		cnt[A[1][i]]++;
	}
	for (int i = 1; i <= N; i++) {
		cnt[A[1][1] - A[i][1]]++;
	}
	// x값 정하기
	int x;
	int max_c = 0;
	for (auto &c : cnt) {
		if (max_c < c.se) {
			x = c.fi;
			max_c = c.se;
		}
	}
	vector<int> row(N + 1), col(M + 1);
	for (int i = 1; i <= N; i++) {
		row[i] = x - (A[1][1] - A[i][1]);
	}
	for (int i = 1; i <= M; i++) {
		col[i] = A[1][i] - x;
	}
	bool posi = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i][j] != row[i] + col[j]) {
				posi = false;
				break;
			}
		}
	}
	if (posi) {
		vector<pii> a1, a2;
		int Q = 0;
		for (int i = 1; i <= N; i++) {
			if (row[i] != 0) {
				Q++;
				a1.push_back({i, row[i]});
			}
		}
		for (int i = 1; i <= M; i++) {
			if (col[i] != 0) {
				Q++;
				a2.push_back({i, col[i]});
			}
		}
		cout << Q << "\n";
		for (int i = 0; i < a1.size(); i++) {
			cout << 1 << " " << a1[i].fi << " " << a1[i].se << "\n";
		}
		for (int i = 0; i < a2.size(); i++) {
			cout << 2 << " " << a2[i].fi << " " << a2[i].se << "\n";
		}
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}