// 무한 수열 
// 1. 구간의 크기가 N이상: A[0]+...+A[N-1] = S라 하면, B[0]+...+B[N-1] = S-N(N + 1)/2, B[i]+...+B[i+N-1] = S-N(N + 1)/2-i*N 이 값이 0이상인 가장 큰 i값(p)을 구함
// 구간의 시작점은 [0, N-1], 끝점은 [p, p + N - 1]에 포함됨
// 2. 구간의 크기가 N미만: [0, 2N - 1] 범위에서 생각
// 예외: p < 2N - 1이면 [0, max(2N - 1, p + N - 1)]에서 생각
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N);
	int s = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		s += A[i];
	}
	int ans = 0;
	// 구간[p, p + N - 1]의 합이 0이상인 최대 p값 구하기
	int p = (s - N*(N + 1)/2) / N;
	//cout << "p: " << p << "\n";
	int sum = 0;
	if (p >= 2 * N - 1) {
		// dp[i]: A[i]를 오른쪽 끝으로 하는 구간의 최대합
		vector<int> dp(2 * N);
		dp[0] = A[0] - 1;
		for (int i = 1; i < 2 * N; i++) {
			if (dp[i - 1] + A[i % N] - (i + 1) > A[i % N] - (i + 1)) {
				dp[i] = dp[i - 1] + A[i % N] - (i + 1);
			}
			else {
				dp[i] = A[i % N] - (i + 1);
			}
		}
		// 길이가 N미만인 경우 계산
		for (int i = 0; i < 2 * N; i++) {
			ans = max(ans, dp[i]);
		}
		// 길이가 N이상일 때
		// 구간 중간 부분 계산(i = N,...,p - 1)
		int quo = (p - N) / N;
		int rem = (p - N) % N;
		//cout << "quonient: " << quo << "\n";
		//cout << "s: " << s << "\n";
		//cout << "s * quo:" << s * quo << "\n";
		sum += s * quo;
		for (int i = N; i < N + rem; i++) {
			sum += A[i % N];
		}
		//cout << "sum: " << sum << "\n";
		sum -= (p - N) * (N + 1 + p) / 2;
		//cout << "min: " << (p - N) * (N + 1 + p) / 2 << "\n";
		// 구간 초기 부분 계산
		sum += dp[N - 1];
		//cout << "start: " << dp[N - 1] << "\n";
		// 구간 마지막 부분 계산
		int pre = 0;
		int max_e = 0;
		for (int i = p; i <= p + N - 1; i++) {
			pre += A[i % N] - (i + 1);
			max_e = max(max_e, pre);
		}
		//cout << "end: " << max_e << "\n";
		ans = max(ans, sum + max_e);
	}
	else { // p < 2 * N - 1
		// dp[i]: A[i]를 오른쪽 끝으로 하는 구간의 최대합
		int len = max(2 * N - 1, p + N - 1);
		vector<int> dp(len + 1);
		dp[0] = A[0] - 1;
		for (int i = 1; i <= len; i++) {
			if (dp[i - 1] + A[i % N] - (i + 1) > A[i % N] - (i + 1)) {
				dp[i] = dp[i - 1] + A[i % N] - (i + 1);
			}
			else {
				dp[i] = A[i % N] - (i + 1);
			}
		}
		for (int i = 0; i <= len; i++) {
			ans = max(ans, dp[i]);
		}
	}
	cout << ans << "\n";

	return 0;
}