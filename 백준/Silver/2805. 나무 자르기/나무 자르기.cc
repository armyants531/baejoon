#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef long long ll;

vector<int> tree;

int cal(int k, int N, int M) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (tree[i] >= k) {
			sum += tree[i] - k;
		}
		if (sum > M) break;	
	}
	return sum;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
	}
	int low = 0;
	int high = 1000000000;
	int max_h = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (cal(mid, N, M) >= M) {
			max_h = max(max_h, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << max_h << "\n";
	
	return 0;
}