// 가지 산사태  // ad-hoc
// 농장이 무너질 때 1층은 항상 무너진다.
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<int> Floor;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	Floor.resize(N + 1);
	int t, r;
	int rain = 0;
	int idx = -1;
	for (int i = 1; i <= M; i++) {
		cin >> t >> r;
		rain += r;
		if (rain > K && idx == -1) {
			idx = i;
		}
	}
	if (idx == -1) {
		cout << idx << "\n";
	}
	else {
		cout << idx << ' ' << 1 << "\n";
	}
	
	return 0;
}