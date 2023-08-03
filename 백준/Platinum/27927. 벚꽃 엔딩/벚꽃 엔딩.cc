// 벚꽃 엔딩  // segment tree + binary search + sweeping 풀이
#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

// 구간 내 E의 최솟값 구하는 세그먼트 트리 초기화
int init_min(vector<int>& a, vector<int>& tree, int idx, int start, int end) {
	if (start == end) {
		return tree[idx] = a[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[idx] = min(init_min(a, tree, idx * 2, start, mid), init_min(a, tree, idx * 2 + 1, mid + 1, end));
	}
}

// 구간 내 S의 최댓값 구하는 세그먼트 트리 초기화
int init_max(vector<int>& a, vector<int>& tree, int idx, int start, int end) {
	if (start == end) {
		return tree[idx] = a[start];
	}
	else {
		int mid = (start + end) / 2;
		return tree[idx] = max(init_max(a, tree, idx * 2, start, mid), init_max(a, tree, idx * 2 + 1, mid + 1, end));
	}
}

// left, right 구간 내 E의 최솟값 구하기
int query_min(vector<int>& tree, int idx, int start, int end, int left, int right) {
	if (end < left || right < start) { // 구간 범위 밖
		return 1000000001;
	}
	else if (left <= start && end <= right) { // 구간 범위 안
		return tree[idx];
	}
	else {
		int mid = (start + end) / 2;
		return min(query_min(tree, idx * 2, start, mid, left, right), query_min(tree, idx * 2 + 1, mid + 1, end, left, right));
	}
}

// left, right 구간 내 S의 최댓값 구하기
int query_max(vector<int>& tree, int idx, int start, int end, int left, int right) {
	if (end < left || right < start) { // 구간 범위 밖
		return 0;
	}
	else if (left <= start && end <= right) { // 구간 범위 안
		return tree[idx];
	}
	else {
		int mid = (start + end) / 2;
		return max(query_max(tree, idx * 2, start, mid, left, right), query_max(tree, idx * 2 + 1, mid + 1, end, left, right));
	}
}

bool posi(int N, int x, vector<int> max_tree, vector<int> min_tree) {
	bool can = false;
	for (int i = 0; i <= N - x; i++) {
		int s_max = query_max(max_tree, 1, 0, N - 1, i, i + x - 1);
		int e_min = query_min(min_tree, 1, 0, N - 1, i, i + x - 1);
		if (s_max <= e_min) {
			can = true;
			break;
		}
	}
	return can;
}

int bsearch(int N, vector<int> max_tree, vector<int> min_tree) {
	int low = 1;
	int high = N;
	int ans = 0; // 연속해서 핀 벚나무 개수의 최댓값
	while (low <= high) {
		int mid = (low + high) / 2;
		if (posi(N, mid, max_tree, min_tree)) {
			low = mid + 1;
			ans = max(ans, mid);
		}
		else {
			high = mid - 1;
		}
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> S(N), E(N);
	vector<int> max_tree(4 * N), min_tree(4 * N);
	vector<pii> c; // 가장 많은 벚나무가 일렬로 연속해서 핀 날의 구간 저장
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> E[i];
	}
	init_min(E, min_tree, 1, 0, N - 1);
	init_max(S, max_tree, 1, 0, N - 1);
	int max_cnt = bsearch(N, max_tree, min_tree);
	for (int i = 0; i <= N - max_cnt; i++) {
		int s_max = query_max(max_tree, 1, 0, N - 1, i, i + max_cnt - 1);
		int e_min = query_min(min_tree, 1, 0, N - 1, i, i + max_cnt - 1);
		if (s_max <= e_min) {
			c.push_back({ s_max, e_min });
			//cout << s_max << " " << e_min << "\n";
		}
	}

	// 가장 많은 벚나무가 일렬로 연속해서 핀 날을 중복 없이 세기(=2170번)
	sort(c.begin(), c.end());
	int len = 0;
	int left = c[0].first;
	int right = c[0].second;
	for (int i = 1; i < c.size(); i++) {
		if (right >= c[i].first) {
			right = max(right, c[i].second);
		}
		else {
			len += right - left + 1;
			left = c[i].first;
			right = c[i].second;
		}
	}
	len += right - left + 1;
	cout << max_cnt << " " << len << "\n";

	return 0;
}