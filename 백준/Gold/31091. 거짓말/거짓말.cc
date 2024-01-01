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
	int N;
	cin >> N;
	map<int, int> mp;
	vector<int> up(N + 1);
	vector<int> down(N + 1);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a > 0) {
			up[a]++;
		} 
		else {
			down[-a]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		up[i] += up[i - 1];
	}
	for (int i = N; i >= 1; i--) {
		down[i - 1] += down[i];
	}
	vector<int> v;
	for (int x = 0; x <= N; x++) {
		if (N - up[x] - down[x] == x) {
			v.push_back(x);
		}
	}
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}