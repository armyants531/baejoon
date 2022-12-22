// 용돈 관리  // binary search  // parametric search
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int N, M;

int check(int k) {
	int money = 0;
	int cnt = 0;
	for (auto i : arr) {
		if (i > money) {
			cnt++;
			money = k - i;
		}
		else {
			money -= i;
		}
	}
	return cnt;
}

int bSearch(int max_money) {
	int start = max_money;
	int end = 1000000000;
	int K = 1000000000;
	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = check(mid);
		if (cnt <= M) {
			K = min(K, mid);
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return K;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int max_money = 0;
	for (int i = 0; i < N; i++) {
		int money;
		cin >> money;
		arr.push_back(money);
		max_money = max(max_money, money);
	}
	cout << bSearch(max_money) << "\n";

	return 0;
}