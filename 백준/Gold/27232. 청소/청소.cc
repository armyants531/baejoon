// 청소  // tree-set
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> arr;
	vector<int> idx(500002); // 장소의 인덱스를 알려줌
	for (int i = 1; i <= N; i++) {
		ll A;
		cin >> A;
		arr.push_back(A);
		idx[A] = i;
	}
	idx[0] = -500000;
	idx[500001] = 1000001;
	ll min_sum = 5000000000000;
	ll sum = 0;
	set<ll> s;
	set<ll>::iterator high, low;
	// 예외처리 대신
	s.insert(0);
	s.insert(500001);
	//sum += idx[500001] - idx[0];
	for (int i = 0; i < K; i++) { // 먼저 K개 채워넣기
		high = s.upper_bound(arr[i]);
		low = high;
		low--;
		if (*low != 0 && *high != 500001) {
			sum -= abs(idx[*high] - idx[*low]);
			sum += abs(idx[*low] - idx[arr[i]]);
			sum += abs(idx[*high] - idx[arr[i]]);
		}
		else if (*low != 0) {
			sum += abs(idx[*low] - idx[arr[i]]);
		}
		else if (*high != 500001) {
			sum += abs(idx[*high] - idx[arr[i]]);
		}
		s.insert(arr[i]);
	}
	min_sum = sum; // update
	for (int i = K; i < N; i++) {
		// 삭제
		high = s.upper_bound(arr[i - K]);
		low = high;
		low--;
		low--; // 한 번 더 감소(arr[i - k] 보다 작은 값 중 가장 큰 값)
		if (*low != 0 && *high != 500001) {
			sum -= abs(idx[*low] - idx[arr[i - K]]);
			sum -= abs(idx[*high] - idx[arr[i - K]]);
			sum += abs(idx[*high] - idx[*low]);
		}
		else if (*low != 0) {
			sum -= abs(idx[*low] - idx[arr[i - K]]);
		}
		else if (*high != 500001) {
			sum -= abs(idx[*high] - idx[arr[i - K]]);
		}
		s.erase(arr[i - K]);
		// 삽입
		high = s.upper_bound(arr[i]);
		low = high;
		low--;
		if (*low != 0 && *high != 500001) {
			sum -= abs(idx[*high] - idx[*low]);
			sum += abs(idx[*low] - idx[arr[i]]);
			sum += abs(idx[*high] - idx[arr[i]]);
		}
		else if (*low != 0) {
			sum += abs(idx[*low] - idx[arr[i]]);
		}
		else if (*high != 500001) {
			sum += abs(idx[*high] - idx[arr[i]]);
		}
		s.insert(arr[i]);
		min_sum = min(sum, min_sum); // update
	}
	cout << min_sum << "\n";
}