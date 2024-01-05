#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;
unordered_map<int, int> m;

double dist(int x, int y, int nx, int ny) {
	double pow = (x - nx) * (x - nx) + (y - ny) * (y - ny);
	return sqrt(pow);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<pii> v(N + 1);
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		v[i] = { x, y };
	}
	vector<int> P(M + 1); // 마킹된 기둥 번호  
	vector<double> R(M + 1); // 범위 
	for (int i = 1; i <= M; i++) {
		cin >> P[i];
	}
	for (int i = 0; i <= M; i++) {
		cin >> R[i];
	}
	for (int i = 1; i <= M; i++) { // 다른 강아지 마킹 
		for (int j = 1; j <= N; j++) {
			if (dist(v[P[i]].fi, v[P[i]].se, v[j].fi, v[j].se) <= R[i]) {
				m[v[j].fi + 60000 * v[j].se] = -1;
				//cout << v[j].fi << " " << v[j].se << "\n"; 
			}
		}
	}
	int ans = 0;
	int cnt = 0;
	while (true) {
		for (int i = 1; i <= N; i++) {
			int x = v[i].fi;
			int y = v[i].se;
			if (m[x + 60000 * y] != 0) continue;
			m[x + 60000 * y] == 1;
			cnt++;
			for (int j = 1; j <= N; j++) { // 시루 소변 냄새 풍김
				int nx = v[j].fi;
				int ny = v[j].se;
				if (m[nx + 60000 * ny] != -1) continue; 
				if (dist(x, y, nx, ny) <= R[0]) {
					m[nx + 60000 * ny] = 0;
				}
			}
		}
		ans += cnt;
		//cout << cnt << "\n";
		cnt = 0;
		if (cnt == 0) break;
	}
	cout << ans << "\n";
	return 0;
}