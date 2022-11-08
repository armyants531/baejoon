// 구간 합 구하기 4  // 누적 합
#include <bits/stdc++.h>

using namespace std;

vector<long long> arr(100001);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	long long prefix_sum = 0;
	long long val;
	arr[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> val;
		prefix_sum += val;
		arr[i] = prefix_sum;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << "\n";
	}
	return 0;
}