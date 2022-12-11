// 공유기 설치  // 이분 탐색
// 가장 인접한 공유기 사이 거리(mid)에 따른 설치 가능한 공유기 개수를 이분 탐색으로 구한다.
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	
	int L = 0;
	int low = 1;
	int high = arr[N - 1] - arr[0];
	while (low <= high) {
		int mid = (low + high) / 2; // mid: 가장 인접한 공유기 사이 거리
		bool isPosible = true;
		int cnt = 1; // 공유기 개수
		int idx = 0; // 마지막 설치한 공유기 인덱스
		int x = arr[0]; // 0번에는 항상 공유기 설치
		while (cnt < C) {
			// x + mid 이상의 값이 처음 나오는 인덱스 구하기
			idx = lower_bound(arr.begin() + idx, arr.end(), x + mid) - arr.begin();
			if (idx > N - 1) {
				isPosible = false;
				break;
			}
			x = arr[idx];
			cnt++;
		}
		if (isPosible) {
			L = max(L, mid);
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << L << "\n";

	return 0;
}