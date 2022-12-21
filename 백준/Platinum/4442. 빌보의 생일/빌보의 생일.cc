// 빌보의 생일  // segment tree  // inversion counting
// map을 통해 입력 받은 문자를 key로, 인덱스를 value로 저장한 후, 두 번째 줄을 입력 받을 때 문자를 숫자로 바꾸어주어 구간 쿼리를 수행한다. 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> tree;

ll interval_sum(int idx, int start, int end, int left, int right) {
	if (right < start || end < left) { // 범위 밖이면
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

// 특정 인덱스의 값에 1을 더해줌(트리의 값이 0 -> 1로 바뀌면서 해당 인덱스의 수가 존재함을 표시)
void update(int idx, int start, int end, int change_idx) {
	if (change_idx < start || end < change_idx) {
		return;
	}
	else if (start == end) {
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
	while (N) {
		tree.resize(4 * N, 0);  // 4*N 크기로 초기화
		ll sum = 0; // 자료형 중요!(교차점의 수가 매우 클 수 있음)
		map<string, int> mp;
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			mp[str] = i;
		}
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			int num = mp[str];
			// 하나씩 추가해가면서 배열의 왼쪽에 있는 수 중 더 큰 수의 개수(입력 받은 수 초과의 구간에서 표시된 1의 개수)를 센다
			sum += interval_sum(1, 0, N - 1, num + 1, N - 1);
			update(1, 0, N - 1, num);
		}
		cout << sum << "\n";
		tree.clear();
		cin >> N;
	}
	
	return 0;
}