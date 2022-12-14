// 커피숍2  // segment tree
// 구간의 합 + 업데이트 함수 구현
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> tree;
vector<ll> arr;

ll init(int idx, int start, int end) {
	if (start == end) {
		return tree[idx] = arr[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[idx] = init(idx * 2, start, mid) + init(idx * 2 + 1, mid + 1, end);
	}
}

ll interval_sum(int idx, int start, int end, int left, int right) {
	if (end < left || right < start) { // 범위 밖이면
		return 0;
	}
	else if (left <= start && end <= right) { // 범위 안이면
		return tree[idx];
	}
	else {
		int mid = (start + end) / 2;
		return interval_sum(idx * 2, start, mid, left, right) + interval_sum(idx * 2 + 1, mid + 1, end, left, right);
	}
}

void update(int idx, int start, int end, int change_idx, ll diff) {
	if (change_idx < start || end < change_idx) {
		return;
	}
	else {
		tree[idx] += diff;
		if (start == end) // 리프 노드이면
			return;
		else {
			int mid = (start + end) / 2;
			update(idx * 2, start, mid, change_idx, diff);
			update(idx * 2 + 1, mid + 1, end, change_idx, diff);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		ll val; 
		cin >> val;
		arr.push_back(val);
	}
	tree.resize(4 * N);
	init(1, 0, N - 1);

	for (int i = 0; i < Q; i++) {
		int x, y, a;
		ll b;
		cin >> x >> y >> a >> b;
		if (x > y) {
			cout << interval_sum(1, 0, N - 1, y - 1, x - 1) << "\n";
		}
		else {
			cout << interval_sum(1, 0, N - 1, x - 1, y - 1) << "\n";
		}
		ll diff = b - arr[a - 1];
		update(1, 0, N - 1, a - 1, diff);
		// arr값 갱신
		arr[a - 1] = b;
	}
	return 0;
}