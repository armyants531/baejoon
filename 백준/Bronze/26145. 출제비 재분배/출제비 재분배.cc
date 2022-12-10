#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> arr(N + M);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N + M; j++) {
			int val;
			cin >> val;
			arr[i] -= val;
			arr[j] += val;
		}
	}
	for (int i = 0; i < N + M; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}