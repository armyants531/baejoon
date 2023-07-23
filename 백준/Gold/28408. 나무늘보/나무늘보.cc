// 나무늘보  // tree
#include <bits/stdc++.h>
#define int long long
int p = 998244353;

using namespace std;

struct Tree {
	int left = -1;    // 현재 노드의 왼쪽 자식 노드 번호
	int right = -1;   // 현재 노드의 오른쪽 자식 노드 번호
	int parent = -1;  // 현재 노드의 부모 노드 번호
};

vector<Tree> tree(500001);
vector<int> pre(500001);
vector<int> post(500001);
vector<int> pre_idx(500001);
vector<int> post_idx(500001);
int n;
int cnt = 0;

void getTree(int num) { // pre의 인덱스을 인자로 전달
	cnt++;
	// pre의 num번째 값 = now
	int now = pre[num];
	if (num + 1 > n) {
		return;
	}
	// 전위 순회의 다음값과 후위 순회의 값이 같아지는 idx1 구한다
	int idx1 = post_idx[pre[num + 1]];
	// 전위 순회의 값과 후위 순회의 값이 같아지는 idx2를 구한다
	int idx2 = post_idx[pre[num]];
	if (idx1 > idx2) { // 잘못됨
		return;
	}
	// 후위 순회의 idx1 번째 값의 부모가 없으면
	if (tree[post[idx1]].parent == -1) {
		tree[now].left = post[idx1];
		tree[post[idx1]].parent = now;
	}
	// 후위 순회의 idx2 - 1번째 값의 부모가 없으면
	if (tree[post[idx2 - 1]].parent == -1) {
		tree[now].right = post[idx2 - 1];
		tree[post[idx2 - 1]].parent = now;
	}
	// 왼쪽 자식 탐색
	getTree(num + 1);
	// 오른쪽 자식 탐색
	if (tree[now].right == -1) {
		return;
	}
	getTree(pre_idx[tree[now].right]);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pre[i];
		pre_idx[pre[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> post[i];
		post_idx[post[i]] = i;
	}
	getTree(1);
	if (cnt != n || pre[1] != post[n]) {
		cout << 0 << "\n";
	}
	else {
		int v = 1;
		for (int i = 1; i <= n; i++) {
			if ((tree[post[i]].right != -1 && tree[post[i]].left == -1) || (tree[post[i]].right == -1 && tree[post[i]].left != -1)) {
				//cout << tree[post[i]].left << " " << tree[post[i]].right << " ";
				v *= 2;
				v %= p;
			}
		}
		cout << v << "\n";
	}
	
	return 0;
}