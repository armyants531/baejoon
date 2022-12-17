// 전깃줄  // DP  // LIS
#include <bits/stdc++.h>

using namespace std;

vector<int> len(100); // i번째 인덱스에서 끝나는 가장 긴 증가 부분 수열의 길이을 저장하는 리스트
vector<int> arr(100); // 여기에서 LIS 구함
vector<pair<int, int>> input;

int LIS(int N) {
	int max_len = 1;
	for (int i = 0; i < N; i++) {
		len[i] = 1;
		for (int j = 0; j < i; j++) { // arr[i] 이전의 원소들 탐색
			if (arr[i] > arr[j]) { // 이전의 원소보다 더 크면
				len[i] = max(len[i], len[j] + 1); // len[i] 갱신
			}
		}
		max_len = max(max_len, len[i]);
	}
	return max_len;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		input.push_back({ A, B });
	}
	sort(input.begin(), input.end());
	// arr 채우기
	for (int i = 0; i < N; i++) {
		arr[i] = input[i].second;
	}
	cout << N - LIS(N) << "\n";

	return 0;
}