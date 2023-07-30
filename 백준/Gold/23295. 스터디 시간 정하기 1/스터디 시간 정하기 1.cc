// 스터디 시간 정하기 1
#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, T;
	cin >> N >> T;
	vector<int> A(100001); // 해당 시간에 몇 명이 있는지 기록
	int start = 100000;
	int end = 0;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			int S, E;
			cin >> S >> E;
			start = min(start, S);
			end = max(end, E);
			A[S]++;
			A[E]--;
		}
	}
	int pre = 0;
	for (int i = start; i < end; i++) {
		pre += A[i];
		A[i] = pre;
	}
	vector<int> B(100002); // A에서의 구간의 합 구하기 위한 누적합 배열 
	pre = 0;
	for (int i = start + 1; i < end + 1; i++) {
		pre += A[i - 1];
		B[i] = pre;
	}
	int max_f = -1;
	int l = 0;
	int r = 0;
	for (int i = start + 1; i <= end + 1 - T; i++) {
		if (B[i + T - 1] - B[i - 1] > max_f) {
			max_f = B[i + T - 1] - B[i - 1];
			l = i - 1;
			r = i + T - 1;
		}
	}
	//cout << max_f << "\n";
	cout << l << " " << r << "\n";

	return 0;
}