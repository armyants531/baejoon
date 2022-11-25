// 세 수의 합  // Meet in the middle  // binary search
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> arr;
vector<ll> two_sum;

// two_sum에서 N의 유무를 리턴
bool binarySearch(ll low, ll high, ll N) {
	while (low <= high) {
		ll mid = (low + high) / 2;
		if (two_sum[mid] == N) {
			return true;
		}
		else if (two_sum[mid] < N)
			low = mid + 1;
		else
			high = mid - 1; 
	}
	return false;
}

int main() {
	ll N;
	cin >> N;
	ll ele;
	for (ll i = 0; i < N; i++) {
		cin >> ele;
		arr.push_back(ele);
	}
	// 두 원소의 합을 저장
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			two_sum.push_back(arr[i] + arr[j]);
		}
	}

	ll max_idx = 0;
	sort(two_sum.begin(), two_sum.end());  // two_sum를 정렬
	
	sort(arr.begin(), arr.end());  // arr를 sort 
	ll low = 0, high = N * N;
	bool breaker = false;
	for (ll i = N - 1; i >= 1; i--) { // 큰 수 부터 탐색
		for (ll j = i - 1; j >= 0; j--) {
			if (binarySearch(low, high, arr[i] - arr[j])) {
				max_idx = i;
				breaker = true;
				break;
			}
		}
		if (breaker)
			break;
	}
	cout << arr[max_idx] << "\n";

	return 0;
}