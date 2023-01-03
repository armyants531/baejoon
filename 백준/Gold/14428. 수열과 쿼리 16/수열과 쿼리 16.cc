// 수열과 쿼리 16  // segment tree
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> arr;
vector<ll> tree;
int N;

// 두 인덱스 중 더 작은 값의 인덱스 리턴
int min_idx(int i, int j) {
	if (i == N + 1) {
		return j;
	}
	if (j == N + 1) {
		return i;
	}
	if (arr[i] == arr[j]) { // 같으면 
		return min(i, j); // 더 작은 인덱스
	}
	else {
		if (arr[i] < arr[j]) {
			return i;
		}
		else {
			return j;
		}
	}
}

void init(int index, int start, int end) {
	if (start == end) {
		tree[index] = start;
		return; 
	}
	else {
		int mid = (start + end) / 2;
		init(index * 2, start, mid);
		init(index * 2 + 1, mid + 1, end);
		tree[index] = min_idx(tree[index * 2], tree[index * 2 + 1]);
		return;
	}
}

int find_min_idx(int index, int start, int end, int left, int right) {
	if (end < left || right < start) { // 구간을 넘어가면
		return N + 1;
	}
	else if (left <= start && end <= right) {
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		return min_idx(find_min_idx(index * 2, start, mid, left, right), find_min_idx(index * 2 + 1, mid + 1, end, left, right));
	}
}

void update(int index, int start, int end, int change_index) {
	// 범위를 벗어난 경우
	if (change_index < start || change_index > end)
		return;
	else {	
		if (start == end) // index를 찾은 경우
			return;
		else {
			int mid = (start + end) / 2;
			update(index * 2, start, mid , change_index);
			update(index * 2 + 1, mid + 1, end, change_index);
			tree[index] = min_idx(tree[index * 2], tree[index * 2 + 1]);
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	arr.resize(N + 1);
	for (int i = 1; i <= N; i++) {	
		cin >> arr[i];
	}
	tree.resize(4 * N + 1);
	init(1, 1, N);  // idx, start, end
	/*
	for (int i = 0; i < tree.size(); i++) {
		cout << tree[i] << " ";
	}
	cout << "\n";
	*/
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int order, x, y;
		cin >> order >> x >> y;
		if (order == 1) {
			arr[x] = y;
			update(1, 1, N, x); // idx, start, end, change_idx
		}
		else {
			cout << find_min_idx(1, 1, N, x, y) << "\n";
		}
	}

	return 0;
}