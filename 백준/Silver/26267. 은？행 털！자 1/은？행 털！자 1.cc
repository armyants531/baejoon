#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct A {
	int t_x;
	ll c;
};

map<int, ll> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int T = 0;
	//vector<A> arr;
	vector<int> key;
	int min_r = 1000000000;
	int max_r = -1000000000;
	for (int i = 0; i < N; i++) {
		int x, t;
		ll c;
		cin >> x >> t >> c;
		//arr.push_back({ t - x, c });
		if (mp[t - x] == 0) {
			key.push_back(t - x);
		}
		mp[t - x] += c;
		//min_r = min(min_r, t - x);
		//max_r = max(max_r, t - x);
	}

	ll max_v = 0;
	for (auto i : key) {
		max_v = max(max_v, mp[i]);
	}

	cout << max_v << "\n";
}