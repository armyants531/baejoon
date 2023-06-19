// 트리의 순회  // tree  // divide and conquer  // recursion
// in-order와 post-order를 통해 pre-order 구하기
// post-order의 마지막이 root node
// in-order에서 root를 기준으로 왼쪽이 left-subtree, 오른쪽이 right-subtree
// https://donggoolosori.github.io/2020/10/15/boj-2263/ 참고
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> inorder;
vector<int> postorder;
vector<int> idx; // 후위 순회에서 찾은 root값이 루트 노드라는 것을 이용하기 위해 중위 순회의 노드 값의 인덱스를 저장 

// pre-order 출력
void preOrder(int in_s, int in_e, int post_s, int post_e) { // idx: inorder start, end, postorder start, end 
	// 더 분할 할 수 없을 때
	if (in_s > in_e || post_s > post_e) {
		return;
	}
	// root 값은 postorder의 끝 값 
	int root_idx = idx[postorder[post_e]];
	// root값 출력
	cout << inorder[root_idx] << " ";
	// inorder의 left, right subtree 원소 개수
	int left_len = root_idx - in_s;
	int right_len = in_e - root_idx;

	preOrder(in_s, root_idx - 1, post_s, post_s + left_len - 1);
	preOrder(root_idx + 1, in_e, post_s + left_len, post_s + left_len + right_len - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	inorder.resize(n + 1);
	postorder.resize(n + 1);
	idx.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> inorder[i];
		idx[inorder[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> postorder[i];
	}

	preOrder(1, n, 1, n);

	return 0;
}