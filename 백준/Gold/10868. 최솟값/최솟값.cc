// 최솟값  // Segment tree
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> arr;
vector<ll> tree;

void init(int idx, int start, int end) {
	if (start == end) {
		tree[idx] = arr[start];
		return;
	}
	else {
		int mid = (start + end) / 2;
		init(idx * 2, start, mid);
		init(idx * 2 + 1, mid + 1, end);
		tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
		return;
	}
}

ll find_min(int idx, int start, int end, int left, int right) {
	if (end < left || right < start) {
		return LLONG_MAX;
	}
	else if (left <= start && end <= right) {
		return tree[idx];
	}
	else {
		int mid = (start + end) / 2;
		return min(find_min(idx * 2, start, mid, left, right), find_min(idx * 2 + 1, mid + 1, end, left, right));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		ll val;
		cin >> val;
		arr.push_back(val);
	}
	tree.resize(4 * N);
	init(1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << find_min(1, 0, N - 1, A - 1, B - 1) << "\n";
	}

	return 0;
}