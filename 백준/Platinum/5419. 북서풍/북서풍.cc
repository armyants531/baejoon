// 북서풍  // segment tree  // 좌표 압축  // 스위핑
// 북서풍을 타면 x좌표는 증가하고, y좌표는 감소
// x좌표에 대해 오름차순 정렬을 하되, 같으면 y좌표에 대해 내림차순으로 정렬한다.
// 순서쌍 개수를 알아내기 위해 x좌표가 작은 순으로(정렬 순으로) 구간 쿼리 수행(y좌표에 대해서는 좌표 압축을 실행하여 인덱스를 구함) 
// https://polohee81.tistory.com/16 참고
// https://blog.naver.com/PostView.naver?blogId=kks227&logNo=220907708368&redirect=Dlog&widgetTypeCall=true&directAccess=false 참고
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

// 특정 인덱스의 노드에 1을 더해줌(구간 내에 특정 인덱스의 수가 존재함을 표시)
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

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;
		tree.resize(4 * n, 0);
		vector<pair<int, int>> coord;
		vector<int> comp_y;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			coord.push_back({ x, y });
			comp_y.push_back(y);
		}
		sort(coord.begin(), coord.end(), compare);
		sort(comp_y.begin(), comp_y.end());
		comp_y.erase(unique(comp_y.begin(), comp_y.end()), comp_y.end());
		ll sum = 0;
		// x좌표에 대해 오름차순, y좌표에 대해 내림차순으로 진행됨
		for (int i = 0; i < n; i++) {
			// coord[i]의 y좌표의 인덱스(0에서 시작)
			int idx = lower_bound(comp_y.begin(), comp_y.end(), coord[i].second) - comp_y.begin();
			// 현재 세그트리에서 idx 이상의 y좌표(좌표압축 됨)를 가진 섬의 갯수 더하기(구간: idx ~ n-1) 
			sum += interval_sum(1, 0, n - 1, idx, n - 1);
			update(1, 0, n - 1, idx); // 구간 합 업데이트
		}
		cout << sum << "\n";
		tree.clear();
	}

	return 0;
}