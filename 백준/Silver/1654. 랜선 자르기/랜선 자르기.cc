// 랜선 자르기  // binary search  // parametric search
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<ll> arr;

int bSearch(int N) {
	ll start = 0;
	ll end = 2147483647; // 2^31 - 1
	ll max_len = 0;
	while (start <= end) {
		ll mid = (start + end) / 2;
		int cnt = 0;
		for (int i = 0; i < arr.size(); i++) {
			cnt += arr[i] / mid; // 각 랜선으로 mid 크기를 만들 수 있는 개수 더하기
		}
		if (cnt >= N) {
			start = mid + 1;
			max_len = max(max_len, mid); // 최대 길이 갱신
		}
		else {
			end = mid - 1;	
		}
	}
	return max_len;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int K, N;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		ll len;
		cin >> len;
		arr.push_back(len);
	}
	cout << bSearch(N) << "\n";

	return 0;
}