// 트리의 높이와 너비  // tree  // dfs  // inorder traverse
// 1. 부모 노드 찾기(한 번 입력됨, 다른 노드는 2번)
// 2. 중위 순회하면서 각 레벨의 최대 열, 최소 열 번호 찾기
// 3. 너비 가장 넓은 레벨을 구하고 그 너비 출력
// https://conkjh032.tistory.com/371 참고
#include <bits/stdc++.h>

using namespace std;

struct Node {
	int left;
	int right;
};

int col = 1;
int max_level = 1;
vector <pair<int, int>> level_arr(10001, {10001, 0});  // 열의 min, max값 저장 
vector<Node> tree(10001);

// 중위 순회
void inorder(int node, int level) {
	if (tree[node].left != -1) {
		inorder(tree[node].left, level + 1);
	}
	// 레벨에 따라 열 값의 최소, 최대 저장
	level_arr[level].first = min(level_arr[level].first, col);
	level_arr[level].second = max(level_arr[level].second, col);
	col++; // 열 값 증가
	max_level = max(max_level, level); // 최대 레벨 갱신 
	if (tree[node].right != -1) {
		inorder(tree[node].right, level + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	// 입력에서 각 노드가 나온 횟수 저장
	vector<int> node_num(N + 1);

	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a] = {b, c};
		node_num[a]++;
		if (b != -1) {
			node_num[b]++;
		}
		if (c != -1) {
			node_num[c]++;
		}
	}
	// find root node
	int root = 1;
	for (int i = 1; i < 10001; i++) {
		if (node_num[i] == 1) {
			root = i;
			break;
		}
	}
	// 중위 순회
	inorder(root, 1); // 루트 노드, 레벨
	// 레벨에 따른 너비 계산
	int max_width = 0;
	int max_width_level;
	for (int i = 1; i <= max_level; i++) {
		int width = level_arr[i].second - (level_arr[i].first - 1);
		if (width > max_width) {
			max_width = width;
			max_width_level = i;
		}
	}
	cout << max_width_level << " " << max_width << "\n";
	return 0;
}