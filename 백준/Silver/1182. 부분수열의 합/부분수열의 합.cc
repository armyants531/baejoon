// 부분수열의 합  // backtracking
// https://velog.io/@dnflrhkddyd/BOJ-%EB%B0%B1%EC%A4%80-1182%EB%B2%88-%EB%B6%80%EB%B6%84%EC%88%98%EC%97%B4%EC%9D%98-%ED%95%A9 참고
// 각 원소들에 대해 선택을 할지, 말지를 정한다.
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int cnt = 0;
// 부분 수열의 합이 S인 경우의 수를 세는 함수
void count_subsequence(int last_idx, int sum, int N, int S) { // last_idx: 현재까지 선택한 마지막 원소의 인덱스, sum 현재 수열의 합
	if (last_idx > N - 1) { // idx범위 0~N-1을 넘어갈 때
		if (sum == S) {
			cnt++;
		}
		return;
	}
	else {
		count_subsequence(last_idx + 1, sum, N, S); // 현재 원소를 합하지 않는 경우
		count_subsequence(last_idx + 1, sum + arr[last_idx], N, S); // 현재 원소를 합하는 경우
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
	count_subsequence(0, 0, N, S);
	if (S == 0) { // S가 0일 때 공집합도 포함되므로 -1 함
		cout << cnt - 1 << "\n";
	}
	else {
		cout << cnt << "\n";
	}
}