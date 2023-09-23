#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

struct dpq {
	int diff, p, q;
};

bool cmp(dpq A, dpq B) {
	return A.diff > B.diff;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, A, B;
	cin >> N >> A >> B;
	int p, q;
	vector<dpq> a;
	for (int i = 0; i < N; i++) {
		cin >> p >> q;
		a.push_back({p-q, p, q});
	}
	sort(a.begin(), a.end(), cmp); // p-q에 대해 내림차순 
	int cost = 0;
	for (int i = 0; i < B; i++) {
		cost += a[i].q; 
	}
	for (int i = B; i < N; i++) {
		cost += a[i].p;
	}
	cout << cost << "\n"; 
	
	return 0;
}