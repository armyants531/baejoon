#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define INF 2000000000000000

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, A;
	cin >> N >> M >> A;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int l = 1;
	int h = a[N - 1];
	int min_v = 100001;
	while (l <= h) {
		int m = (l + h) / 2;
		int p = 0;
		int abil = m;
		for (int i = 0; i < M; i++) {
			int idx = upper_bound(a.begin(), a.end(), abil) - a.begin(); // 처음으로 초과하는 값의 인덱스 
			idx--;
			if (idx < 0) {
				break;
			}
			abil += a[idx]; // 맞출 수 있는 최대값 더하기 
		}
		if (abil - m >= A) {
			min_v = min(min_v, m);
			//cout << m << " " << abil - m << "\n";
			h = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	cout << min_v << "\n";

	return 0;
}