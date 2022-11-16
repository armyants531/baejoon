// 가장 긴 감소 부분 수열  // dp  // LDS 
#include <bits/stdc++.h>

using namespace std;

vector<int> length(1000); // i번째 인덱스에서 끝나는 가장 긴 감소 부분 수열의 길이을 저장하는 리스트
vector<int> arr(1000);

int LDS(int n) {
	int max_length = 1;
	for (int x = 0; x < n; x++) {
		length[x] = 1;
		// length[x] 갱신
		for (int i = 0; i < x; i++) { // 0 ~ x-1 인덱스를 가진 리스트 원소 중 
			if (arr[x] < arr[i]) { // arr[x] 보다 큰 원소가 있으면
				length[x] = max(length[x], 1 + length[i]);
			}
		}
		max_length = max(max_length, length[x]);
	}
	return max_length;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << LDS(N) << "\n";

	return 0;
} 