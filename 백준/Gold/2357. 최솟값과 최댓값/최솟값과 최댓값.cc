#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef struct val { // 세그먼트 트리의 노드에 저장되는 값(구간에서의 최대, 최솟값)
	long long min;
	long long max;
} VAL;

long long* arr;
VAL* tree;

void init(int index, int start, int end) {
	if (start == end) {
		tree[index].min = tree[index].max = arr[start];
		return;
	}
	else {
		int mid = (start + end) / 2;
		init(index * 2, start, mid);
		init(index * 2 + 1, mid + 1, end);
		tree[index].min = min(tree[index * 2].min, tree[index * 2 + 1].min);
		tree[index].max = max(tree[index * 2].max, tree[index * 2 + 1].max);
		return;
	}
}

long long find_min(int index, int start, int end, int left, int right) {
	if (right < start || left > end)
		return LLONG_MAX;
	else if (left <= start && right >= end)
		return tree[index].min;
	else {
		int mid = (start + end) / 2;
		return min(find_min(index * 2, start, mid, left, right), find_min(index * 2 + 1, mid + 1, end, left, right));
	}
}

long long find_max(int index, int start, int end, int left, int right) {
	if (right < start || left > end)
		return LLONG_MIN;
	else if (left <= start && right >= end)
		return tree[index].max;
	else {
		int mid = (start + end) / 2;
		return max(find_max(index * 2, start, mid, left, right), find_max(index * 2 + 1, mid + 1, end, left, right));
	}
}

int main() {
	// a, b 쌍이 최대 100,000개가 주어짐 -> 입출력 시간 줄이기!
	ios::sync_with_stdio(false); // C++ stream들이 독립적인 buffer를 가지게 함
	cin.tie(NULL); 
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	arr = new long long[n]();
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	tree = new VAL[4 * n]();
	init(1, 0, n-1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		long long min = find_min(1, 0, n-1, a-1, b-1);
		long long max = find_max(1, 0, n-1, a-1, b-1);
		cout << min << " " << max << "\n";
	}
	
	return 0;
}