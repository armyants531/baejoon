// 성향 성장의 비약  // 이분 탐색  // 매개변수 탐색 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> level;
vector<ll> item;

// goal까지 모든 레벨을 올리는데 필요한 아이템(성향 성장의 비약)의 수
ll check(ll goal, int N) {
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		if (goal > level[i]) {
			ll cal = goal - level[i];
			sum += cal;
		}
		if (sum > 1000000000000) {
			break;
		}
	}
	return sum;
}

ll bSearch(ll low, ll high, ll items, int N) {
	ll max_level = 0;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (check(mid, N) <= items) {
			max_level = max(max_level, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return max_level;
}

// goal까지 레벨을 올리는 데 필요한 성향 아이템 수 구하기
ll check0(ll goal, ll current_level) {
	ll sum = 0;
	if (goal > current_level) {
		sum = (goal - current_level) * (current_level + goal - 1) / 2;
	}
	return sum;
}

ll bSearch0(ll low, ll high, ll items, ll current_level) {
	ll max_level = current_level;
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (check0(mid, current_level) <= items) {
			max_level = max(max_level, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return max_level;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	ll M;
	cin >> N >> M;
	level.resize(N);
	ll max_level = 0;
	for (int i = 0; i < N; i++) {
		cin >> level[i];
		max_level = max(max_level, level[i]);
	}
	item.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> item[i];
		level[i] = bSearch0(0, 1800000000, item[i], level[i]);
	}
	// 성향 성장의 비약까지 투입 후 정N각형을 이루는 최대 레벨과 처음 입력 받은 레벨 중 최댓값 비교
	ll ans = bSearch(0, 1000000000000, M, N);
	if (ans < max_level) {
		cout << -1 << "\n";
	}
	else { 
		cout << ans << "\n";
	}
	return 0;
}