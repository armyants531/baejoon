// 스터디 카페  // sweeping  // prefix sum
// https://ps.mjstudio.net/boj-28284 참고 
#include <bits/stdc++.h>
#define int long long

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	// 인원 수에 따른 최소, 최대 수익 미리 계산
	sort(A.begin(), A.end());
	vector<int> A_min(N);
	int min_pre = 0;
	for (int i = 0; i < N; i++) {
		min_pre += A[i];
		A_min[i] = min_pre;
	}
	reverse(A.begin(), A.end());

	vector<int> A_max(N);
	int max_pre = 0;
	for (int i = 0; i < N; i++) {
		max_pre += A[i];
		A_max[i] = max_pre;
	}
	int S, E;
	int max_E = 0;
	int len = 0;
	vector<int> T;
	vector<pii> event;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		T.push_back(S);
		T.push_back(E + 1);
		// 누적합 위한 작업
		event.push_back({ S, 1 }); // 더하는 값
		event.push_back({ E + 1, -1 }); // 빼야하는 값
	}

	sort(T.begin(), T.end());
	// 중복값 제거 
	T.erase(unique(T.begin(), T.end()), T.end());
	sort(event.begin(), event.end());
	// sweeping
	int pre_sum = 0;
	int max_s = 0;
	int min_s = 0;
	T.push_back(T.back() + 1); // for T[i + 1] - T[i]
	int j = 0;
	for (int i = 0; i < T.size() - 1; i++) {
		while (j < event.size() && event[j].first <= T[i]) {
			pre_sum += event[j].second;
			j++;
		}
		if (pre_sum >= 1) {
			max_s += A_max[pre_sum - 1] * (T[i + 1] - T[i]);
			min_s += A_min[pre_sum - 1] * (T[i + 1] - T[i]);
		}
	}

	cout << min_s << " " << max_s << "\n";

	return 0;
}