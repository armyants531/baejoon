// 사탕상자  // segment tree  // binary search
// https://yabmoons.tistory.com/472 참고
// 사탕의 갯수를 저장하는 구간 합 세그먼트 트리: 리프 노드에 맛이 start(== end)인 사탕의 개수가 저장
// x번 째 사탕: 왼쪽 노드의 사탕이 x개 이상-> 왼쪽 노드 탐색 / x개 미만(y개)-> 오른쪽 노드에서 x-y번 째 사탕 찾기
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> tree(4000000); // 사탕의 갯수를 저장하는 세그먼트 트리
vector<ll> arr(1000001, 0); // arr[i] : 맛이 i인 사탕의 개수

// x번 째 사탕의 맛을 찾아 리턴하는 구간 쿼리
int query(int idx, int start, int end, int x) { // idx: tree의 인덱스, start/end: 사탕의 맛의 최소, 최댓값 
	if (start == end) {
		return start;
	}
	else {
		int mid = (start + end) / 2;
		int idx_2 = idx * 2;
		if (tree[idx_2] >= x) { // (start ~ mid 구간의 맛을 가진 사탕의 개수) >= x
			return query(idx_2, start, mid, x); // 왼쪽 자식 노드 탐색
		}
		else { // (start ~ mid 구간의 맛을 가진 사탕의 개수) < x
			return query(idx_2 + 1, mid + 1, end, x - tree[idx_2]); // 오른쪽 자식 노드 탐색
		}
	}
}

void update(int idx, int start, int end, int changed_val, int diff) {
	if (changed_val < start || end < changed_val) {
		return;
	}
	else {
		tree[idx] += diff;
		if (start == end) { // if leef node
			return;
		}
		int idx_2 = idx * 2;
		int mid = (start + end) / 2;
		update(idx_2, start, mid, changed_val, diff);
		update(idx_2 + 1, mid + 1, end, changed_val, diff);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B, C;
		cin >> A;
		if (A == 1) {
			cin >> B;
			int taste = query(1, 1, 1000000, B);
			cout << taste << "\n";
			arr[taste]--;
			update(1, 1, 1000000, taste, -1);
		}
		else {
			cin >> B >> C;
			arr[B] += C;
			update(1, 1, 1000000, B, C);
		}
	}
}