// 냅색문제  // Meet in the middle // dfs
// https://baebalja.tistory.com/254 참고
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> arr;
vector<ll> left_arr, right_arr;

void dfs(ll last_idx, ll sum, ll end, vector<ll>& part_arr) { // last_idx: 현재까지 선택한 마지막 원소의 인덱스, sum 현재 수열의 합
	if (last_idx == end) {
		part_arr.push_back(sum);
		return;
	}
	dfs(last_idx + 1, sum, end, part_arr); // last_idx의 물건을 넣지 않는 경우
	dfs(last_idx + 1, sum + arr[last_idx], end, part_arr); // last_idx의 물건을 넣는 경우
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, C;
	cin >> N >> C;
	int val;
	for (int i = 0; i < N; i++) {
		cin >> val;
		arr.push_back(val);
	}
	ll mid = N / 2;
	// 배열을 좌우로 나누어 dfs 진행(시간 초과 방지)
	dfs(0, 0, mid, left_arr);
	dfs(mid, 0, N, right_arr);
	sort(left_arr.begin(), left_arr.end()); // left_arr 정렬

	ll cnt = 0; 
	for (int i = 0; i < right_arr.size(); i++) {
		// upper_bound: 찾으려는 val(key) 값보다 큰 숫자가 배열 몇 번째에서 처음으로 등장하는지를 리턴(반환형: iterator)
		cnt += upper_bound(left_arr.begin(), left_arr.end(), C - right_arr[i]) - left_arr.begin(); // left_arr의 원소 중 C - right_arr[i] 이하의 원소 개수 더하기
	}
	cout << cnt << "\n";
}