// 성싶당 밀키트  // 이분 탐색  // 매개변수 탐색  // greedy
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

vector<pair<ull, ull>> imp;
vector<pair<ull, ull>> notImp;

ull check(ull mid, ull G, ull K) {
	ull cnt = 0;
	for (ull i = 0; i < imp.size(); i++) {
		if (imp[i].second + 1 >= mid) {
			cnt += imp[i].first;
		}
		else {
			cnt += imp[i].first * (mid - imp[i].second);
		}
		if (cnt > G) { // 오버 플로우 방지
			return G + 1;
		}
	}
	vector<ull> germs;
	for (ull i = 0; i < notImp.size(); i++) {
		if (notImp[i].second + 1 >= mid) {
			germs.push_back(notImp[i].first);
		}
		else {
			germs.push_back(notImp[i].first * (mid - notImp[i].second));
		}
	}
	sort(germs.begin(), germs.end());
	if (notImp.size() > K) {
		for (ull i = 0; i < notImp.size() - K; i++) {
			cnt += germs[i];
		}
		if (cnt > G) {
			return G + 1;
		}
	}
	
	return cnt;
}

ull bSearch(ull low, ull high, ull G, ull K) {
	ull ans;
	while (low <= high) {
		ull mid = (low + high) / 2;
		ull cnt = check(mid, G, K); // mid일의 세균 수
		if (cnt <= G) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ull N, G, K;
	cin >> N >> G >> K;
	for (int i = 0; i < N; i++) {
		ull S, L, O;
		cin >> S >> L >> O;
		if (O == 1) {
			notImp.push_back({ S, L });
		}
		else {
			imp.push_back({ S, L });
		}
	}
	cout << bSearch(0, 2000000000, G, K) << "\n";

	return 0;
}