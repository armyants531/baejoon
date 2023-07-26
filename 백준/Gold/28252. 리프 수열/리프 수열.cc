#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n);
	int pre = 100001;
	bool posi = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (pre < a[i]) posi = false;
		pre = a[i];
	}
	if (a[n - 1] > 2) { // 루트 노드는 2개 이하
		posi = false;
	}
	else if (n >= 2 && a[n - 1] == 1 && a[n - 2] == 1) { // 1이 2개 이상 존재
		posi = false;
	}
	if (posi) {
		reverse(a.begin(), a.end()); // a를 뒤집기
		vector<vector<int>> tree(n);
		int num = 0; // 트리 정점의 개수(번호)
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < a[i]; j++) {
				num++;
				tree[i].push_back(num);
			}
		}
		cout << num << "\n";
		// root 노드가 2개이면 서로 매칭
		if (a[0] == 2) {
			cout << 1 << " " << 2 << "\n";
		}
		// 자식 노드와 부모 노드를 매칭 
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < tree[i + 1].size(); j++) {
				cout << tree[i][j % tree[i].size()] << " " << tree[i + 1][j] << "\n";
			}
		}
	}
	else {
		cout << -1 << "\n";
	}
	
	return 0;
}