// K번째 수  // segment tree  // merge sort tree
// query(index, start, end, left, right, num) : (start, end) 구간 내에 num보다 작은 숫자가 몇 개인지 리턴
// 이분 탐색을 통해 num보다 작은 숫자가 k - 1개 인 경우 중 가장 큰 num을 구하면 됨(이것이 k번 째 수)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> tree[400000];
vector<ll> arr(100001);

void init(int index, int start, int end) {
	if (start == end) { // 리프 노드
		tree[index].push_back(arr[start]);
		return;
	}
	int mid = (start + end) / 2;
	init(index * 2, start, mid);
	init(index * 2 + 1, mid + 1, end);
	merge(tree[index * 2].begin(), tree[index * 2].end(), tree[index * 2 + 1].begin(), tree[index * 2 + 1].end(), inserter(tree[index], tree[index].begin()));
}

// 구간 내의 num 보다 작은 수의 개수를 리턴하는 함수 
int query(int index, int start, int end, int left, int right, int num) {
	if (end < left || right < start) { // 완전히 구간 밖
		return 0;
	}
	else if (left <= start && end <= right) { // 완전히 구간 안
		return lower_bound(tree[index].begin(), tree[index].end(), num) - tree[index].begin();
	}
	else {
		int mid = (start + end) / 2;
		return query(index * 2, start, mid, left, right, num) + query(index * 2 + 1, mid + 1, end, left, right, num);
	}
}

// num 보다 작은 수의 개수가 k-1개인 num 중 가장 큰 수를 리턴
int binarySearch(int N, int i, int j, int k) {
	int start = -1000000000;
	int end = 1000000000;
	int ans = -1000000001;
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = query(1, 1, N, i, j, mid);
		if (cnt <= k - 1) {
			start = mid + 1;
			ans = max(ans, mid);
		}
		else { // cnt > k - 1
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init(1, 1, N); // index, start, end
	for (int l = 0; l < M; l++) {
		int i, j, k;
		cin >> i >> j >> k;
		cout << binarySearch(N, i, j, k) << "\n";
	}

	return 0;
}