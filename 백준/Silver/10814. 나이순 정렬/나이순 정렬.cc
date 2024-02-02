#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

struct info {
	int y, idx;
	string name;
}; 

bool cmp(info A, info B) {
	if (A.y == B.y) {
		return A.idx < B.idx;
	}
	return A.y < B.y;
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<info> v(N);
	for (int i = 0; i < N; i++) {
		int y;
		string s;
		cin >> y >> s;
		v[i] = {y, i, s};
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << v[i].y << " " << v[i].name << "\n"; 
	}
	return 0;
}