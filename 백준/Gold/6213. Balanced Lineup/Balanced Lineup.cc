// Balanced Lineup  // Segment tree
// 구간의 최대값 - 최솟값
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct val {
	ll min_val;
	ll max_val;
};

vector<ll> arr;
vector<val> tree;

void init(int index, int start, int end) { // start, end: 시작, 끝 인덱스
	if (start == end) {
		tree[index].min_val = tree[index].max_val = arr[start];
		return;
	}
	else {
		int mid = (start + end) / 2;
		// 자식 노드 초기화
		init(index * 2, start, mid);
		init(index * 2 + 1, mid + 1, end);
		tree[index].min_val = min(tree[index * 2].min_val, tree[index * 2 + 1].min_val);
		tree[index].max_val = max(tree[index * 2].max_val, tree[index * 2 + 1].max_val);
		return;
	}
}

ll find_min(int index, int start, int end, int left, int right) { // left, right 찾으려는 구간
	if (right < start || left > end) { // 찾는 구간 밖에 있으면 
		return LLONG_MAX;
	}
	else if (left <= start && end <= right) { // 찾는 구간 내에 있으면
		return tree[index].min_val;
	}
	else {
		int mid = (start + end) / 2;
		return min(find_min(index * 2, start, mid, left, right), find_min(index * 2 + 1, mid + 1, end, left, right));
	}
}

ll find_max(int index, int start, int end, int left, int right) {
	if (right < start || left > end) { // 찾는 구간 밖에 있으면
		return LLONG_MIN;
	}
	else if (left <= start && end <= right) { // 찾는 구간 내에 있으면
		return tree[index].max_val;
	}
	else {
		int mid = (start + end) / 2;
		return max(find_max(index * 2, start, mid, left, right), find_max(index * 2 + 1, mid + 1, end, left, right));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		ll h;
		cin >> h;
		arr.push_back(h);
	}
	tree.resize(4 * N);
	init(1, 0, N - 1);

	for (int i = 0; i < Q; i++) {
		int A, B;
		cin >> A >> B;
		ll min = find_min(1, 0, N - 1, A - 1, B - 1);
		ll max = find_max(1, 0, N - 1, A - 1, B - 1);
		cout << max - min << "\n";
	}

	return 0;
}