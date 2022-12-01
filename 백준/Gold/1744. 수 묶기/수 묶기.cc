// 수 묶기  // greedy
#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {
	int N;
	cin >> N;
	int val;
	for (int i = 0; i < N; i++) {
		cin >> val;
		arr.push_back(val);
	}
	// 오름차순 정렬
	sort(arr.begin(), arr.end());
	int sum = 0;
	int i;
	// 앞에서부터
	for (i = 0; i < N - 1; i++) {
		if (arr[i + 1] <= 0) { // 인접한 두 수가 모두 0 이하이면
			sum += arr[i] * arr[i + 1]; // 두 수 묶기
			i++;
		}
		else if (arr[i] <= 0 && arr[i + 1] > 0) { // 다음 수가 0보다 크면
			sum += arr[i];
		}
		else {
			break;
		}
	}
	// 뒤에서부터
	for (i = N - 1; i >= 1; i--) {
		if (arr[i - 1] > 1) { // 인접한 두 수가 모두 1 초과이면
			sum += arr[i] * arr[i - 1]; // 두 수 묶기
			i--;
		}
		else if (arr[i - 1] <= 1 && arr[i] >= 1) { // 현재 수는 1이상이고, 앞의 수가 1이하이면  
			sum += arr[i];
		}
		else {
			break;
		}
	}
	// 묶이지 않은 것 처리
	// 모두 음수이면 
	if (arr[N - 1] < 0) {
		if (N % 2) { // N이 홀수 이면
			sum += arr[N - 1];
		}
	}
	// 모두 1이상의 양수이면 
	if (arr[0] >= 1) {
		if (N % 2 || arr[0] == 1) { // N이 홀수이거나 arr[0] == 1 이면
			sum += arr[0];
		}
	}
	cout << sum << "\n";

	return 0;
}