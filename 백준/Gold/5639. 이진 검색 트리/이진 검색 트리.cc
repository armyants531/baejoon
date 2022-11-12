// 이진 검색 트리 // tree // recursion
// https://ongveloper.tistory.com/295 참고
#include <bits/stdc++.h>

using namespace std;

vector<int> tree(10000);
void postorder(int start, int end) {
	if (start > end - 1)
		return;

	int i;
	for (i = start + 1; i < end; i++) {
		if (tree[start] < tree[i]) { // start 노드 보다 크면 종료
			break;
		}
	}
	postorder(start + 1, i); // 왼쪽 [start + 1, i)
	postorder(i, end); // 오른쪽 [i, end)
	cout << tree[start] << "\n"; // root
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, i = 0;
	/*
	for (i; i < 9; i++) { // 테스트용
		cin >> n;
		tree[i] = n;
	}
	*/
	while (cin >> n) {
		tree[i] = n;
		i++;
	}
	postorder(0, i);
}