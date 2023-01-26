// 이진 탐색 트리  // tree-map
// C는 기존의 트리에 노드가 삽입이 될 때 노드의 깊이의 누적합
// map<key, val> : key에 n값, val에 노드의 깊이 저장
// depth = max(down의 depth, up의 depth) + 1
// https://everenew.tistory.com/102 참고
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	ll C = 0; // 정수형 범위 초과 가능(주의!)
	map<int, int> tree;
	map<int, int>::iterator up, down; // n보다 큰 값 중 최소, n보다 작은 값 중 최대
	// n보다 큰 값이나 작은 값이 없는 경우를 고려해 깊이가 -1인 가상의 노드를 넣는다. 
	tree.insert({ 0, -1 }); 
	tree.insert({ 300001, -1 });
	cin >> N;
	int n;
	for (int i = 0; i < N; i++) {
		cin >> n;
		up = tree.upper_bound(n); // n보다 큰 값 중 최소값 찾기
		down = up;
		down--;
		int depth = max(up->second, down->second) + 1;
		C += depth;
		cout << C << "\n";
		tree.insert({ n, depth });
	}
	
	return 0;
}