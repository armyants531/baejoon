// 히스토그램에서 가장 큰 직사각형  // 분할 정복  // greedy
// https://sgc109.github.io/2021/03/18/largest-rectangle-in-histogram/ 참고
// O(nlog n)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> arr;

ll sol(int left, int right) {
	if (left == right) { 
		return arr[left];
	}
	int mid = (left + right) / 2;
	ll area = max(sol(left, mid), sol(mid + 1, right));
	// mid 양쪽에 left, right가 걸쳐 있음
	// 두 포인터를 가운데의 두 막대를 가리키도록 초기화
	int lp = mid;
	int rp = mid + 1;
	// 두 포인터를 바깥쪽으로 이동시키면서 답을 갱신
	ll min_h = 1000000001;
	while (left <= lp && rp <= right) {
		min_h = min({ arr[lp], min_h, arr[rp] });
		area = max(area, min_h * (rp - lp + 1));
		// 두 포인터 중 다음 막대의 높이가 더 높은 것을 이동시킴
		if (lp == left) {
			rp++;
		}
		else if (rp == right) {
			lp--;
		}
		else if (arr[lp - 1] > arr[rp + 1]) {
			lp--;
		}
		else {
			rp++;
		}
	}
	return area;
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			arr.push_back(val);
		}
		cout << sol(0, n - 1) << "\n";

		arr.clear();
	}

	return 0;
}