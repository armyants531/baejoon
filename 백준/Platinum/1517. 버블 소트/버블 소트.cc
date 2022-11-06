// 버블 소트 // 세그먼트 트리
#include <iostream>
#include <vector>
#include <algorithm> // lower_bound, unique, sort

using namespace std;

int tree[500000 * 4] = { 0, }; // 세그먼트 트리 초기화
vector<long long> v;

// [left, right] 구간 합을 구하는 함수
// compress_cor(left - 1)보다 큰 수의 개수를 구하는 함수이다.
// https://barbera.tistory.com/41 를 참고하면 내용 이해에 좋다.
int query(int start, int end, int index, int left, int right) {
	if (start > right || end < left)
		return 0;
	else if (left <= start && end <= right)
		return tree[index];
	else {
		int mid = (start + end) / 2;
		return query(start, mid, index * 2, left, right) + query(mid + 1, end, index * 2 + 1, left, right);
	}
}

// 특정 인덱스의 값에 1을 더해 주는 함수
void update(int start, int end, int index, int change_index) {
	if (change_index < start || change_index > end)
		return;
	else if (start == end) {
		tree[index]++;
		return;
	}
	else {
		tree[index]++;
		int mid = (start + end) / 2;
		update(start, mid, index * 2, change_index);
		update(mid + 1, end, index * 2 + 1, change_index);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long sum = 0;
	int N;
	cin >> N;
	vector<long long> copy;
	for (int i = 0; i < N; i++) {
		long long val;
		cin >> val;
		v.push_back(val);
		copy.push_back(val);
	}
	sort(v.begin(), v.end()); // 오름차순 정렬
	v.erase(unique(v.begin(), v.end()), v.end()); // 중복값 제거
	for (int i = 0; i < N; i++) {
		int compress_cor = lower_bound(v.begin(), v.end(), copy[i]) - v.begin(); // 0부터 시작
		sum += query(0, N - 1, 1, compress_cor + 1, N - 1); // [compress_cor + 1, N - 1] 구간 합
		update(0, N - 1, 1, compress_cor);
	}

	cout << sum << "\n";
	return 0;
}