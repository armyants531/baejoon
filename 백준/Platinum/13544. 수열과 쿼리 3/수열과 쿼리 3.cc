// 수열과 쿼리 3  // segment tree  // merge sort tree
// https://arnold518.tistory.com/56?category=767009 참고
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

// 구간 내의 k보다 큰 수의 개수 리턴
int query(int index, int start, int end, int left, int right, int k) {
	if (end < left || right < start) { // 완전히 구간 밖
		return 0;
	}
	else if (left <= start && end <= right) { // 완전히 구간 안
		return tree[index].end() - upper_bound(tree[index].begin(), tree[index].end(), k);
	}
	else {
		int mid = (start + end) / 2;
		return query(index * 2, start, mid, left, right, k) + query(index * 2 + 1, mid + 1, end, left, right, k);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init(1, 1, N); // index, start, end
	int last_ans = 0;
	int M;
	cin >> M;
	for (int l = 0; l < M; l++) {
		int a, b, c;
		cin >> a >> b >> c;
		int i = (a ^ last_ans); 
		int j = (b ^ last_ans); 
		int k = (c ^ last_ans);
		last_ans = query(1, 1, N, i, j, k);
		
		cout << last_ans << "\n";
	}

	return 0;
}