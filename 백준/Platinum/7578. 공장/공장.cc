// 공장  // segment tree  // inversion counting
// 기본적인 inversion counting 문제
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> tree;
map<int, int> mp;

ll interval_sum(int idx, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[idx];
	}
	else {
		int mid = (start + end) / 2;
		return interval_sum(idx * 2, start, mid, left, right) + interval_sum(idx * 2 + 1, mid + 1, end, left, right);
	}
}

// change_idx가 포함된 구간에 존재하는 수의 개수 + 1
void update(int idx, int start, int end, int change_idx) {
	if (change_idx < start || end < change_idx) { // 범위 밖이면 
		return;
	}
	else if (start == end) { // 리프 노드이면
		tree[idx]++;
		return;
	}
	else {
		tree[idx]++;
		int mid = (start + end) / 2;
		update(idx * 2, start, mid, change_idx);
		update(idx * 2 + 1, mid + 1, end, change_idx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	tree.resize(4 * N, 0);
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		mp[val] = i;
	}
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		int idx = mp[val];
		sum += interval_sum(1, 0, N - 1, idx + 1, N - 1);
		update(1, 0, N - 1, idx);
	}
	cout << sum << "\n";

	return 0;
}