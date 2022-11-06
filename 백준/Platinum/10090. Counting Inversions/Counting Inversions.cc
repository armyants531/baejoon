// Counting Inversions // 세그먼트 트리
#include <iostream>
#include <vector>
#include <algorithm> // lower_bound, unique, sort

using namespace std;

long long tree[1000000 * 4] = { 0, }; // 세그먼트 트리 초기화

// [left, right] 구간 합을 구하는 함수
long long interval_sum(int start, int end, int index, int left, int right) {
	if (start > right || end < left) // 구간이 겹치지 않는 경우
		return 0;
	else if (left <= start && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return interval_sum(start, mid, index * 2, left, right) + interval_sum(mid + 1, end, index * 2 + 1, left, right);
	}
}

// 특정 인덱스의 값에 1을 더해 주는 함수
// 배열에 어떤 수(현재 코드에서는 change_index - 1)가 추가되었는지 표시한다
void update(int start, int end, int index, int change_index) {
	if (change_index < start || change_index > end) // 범위 밖이면
		return;
	else if (start == end) { // left node이면
		tree[index]++;
		return;
	}
	else {
		tree[index]++;
		int mid = (start + end) / 2;
		// 자식 노드 정보 업데이트
		update(start, mid, index * 2, change_index);
		update(mid + 1, end, index * 2 + 1, change_index);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v; // 원본 벡터(sort 시행)
	vector<int> copy; // 원래 벡터의 복사본 
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
		copy.push_back(val);
	}
	long long count = 0;
	sort(v.begin(), v.end()); // 정렬
	// 처음에는 update만 한다.
	update(0, n - 1, 1, copy[0]);
	for (int i = 1; i < n; i++) {
		int coord = copy[i] - 1;
		count += interval_sum(0, n - 1, 1, coord + 1, n - 1); // [coord + 1, n - 1] 구간 합
		update(0, n - 1, 1, coord);
	}

	cout << count << "\n";
	return 0;
}