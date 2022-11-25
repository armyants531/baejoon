// Parcel  // Meet in the middle  // DP
// https://velog.io/@rootachieve/%EB%B0%B1%EC%A4%80-16287-Parcel 참고
// 기준을 움직여가면서 양옆으로 2개씩 뽑는다(중복 방지)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> arr;
vector<bool> two_sum(800000, false);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll w;
	int n;
	cin >> w >> n;
	bool isExist = false;
	ll val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		arr.push_back(val);
	}
	// 기준점 i를 2부터 n-2까지 잡고, 양쪽에서 2개씩 고른다. 
	for (int i = 2; i < n - 1; i++) {
		// arr의 왼쪽에서 두 원소를 뽑아 더한 값(two_ele)을 w에서 뺀 값이 two_sum에 존재하는지 확인
		// 왼쪽에서 2개 고르기(0 ~ i-1) // j번째와 i-1번째 선택
		for (int j = 0; j < i - 1; j++) {
			two_sum[arr[j] + arr[i - 1]] = true;
		}
		// 오른쪽에서 2개 고르기(i ~ n-1) // i번째와 j번째 선택
		for (int j = i + 1; j < n; j++) {
			int rightSum = arr[i] + arr[j];
			if (rightSum <= w && two_sum[w - rightSum]) {
				isExist = true;
				break;
			}
		}
		if (isExist)
			break;
	}
	if (isExist)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}