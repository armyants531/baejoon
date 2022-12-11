// 수 찾기  // 이분 탐색
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int binarySearch(int num) {
	int start = 0;
	int end = arr.size() - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == num) {
			return 1;
		}
		else if (arr[mid] < num) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}
	// 오름차순 정렬
	sort(arr.begin(), arr.end());
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		cout << binarySearch(num) << "\n";
	}

	return 0;
}