// 부분수열의 합 2  // Meet in the middle
// https://hyeo-noo.tistory.com/128 참고
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
map<int, int> sub_sum; // <key, val>
long long cnt = 0;

// 왼쪽 부분 수열의 합을 key로, 합을 만드는 경우의 수를 value로 가지는 map 형성
void count_left(int last_idx, int sum, int mid) { // last_idx: 현재까지 선택한 마지막 원소의 인덱스, sum 현재 수열의 합
	if (last_idx > mid - 1) {
		sub_sum[sum]++;
		return;
	}
	else {
		count_left(last_idx + 1, sum, mid); // 현재 원소를 합하지 않는 경우
		count_left(last_idx + 1, sum + arr[last_idx], mid); // 현재 원소를 합하는 경우
	}
}

void count_right(int last_idx, int sum, int end, int S) { // last_idx: 현재까지 선택한 마지막 원소의 인덱스, sum 현재 수열의 합
	if (last_idx == end) {
		cnt += sub_sum[S - sum]; // S-sum을 key로 갖는 value값을 더해줌
		return;
	}
	else {
		count_right(last_idx + 1, sum, end, S); // 현재 원소를 합하지 않는 경우
		count_right(last_idx + 1, sum + arr[last_idx], end, S); // 현재 원소를 합하는 경우
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, S;
	cin >> N >> S;
	int val;
	for (int i = 0; i < N; i++) {
		cin >> val;
		arr.push_back(val);
	}
	int mid = N / 2;
	count_left(0, 0, mid);
	count_right(mid, 0, N, S);
	if (S == 0) { // S가 0일 때 공집합도 포함되므로 -1 함
		cout << cnt - 1 << "\n";
	}
	else {
		cout << cnt << "\n";
	}
}