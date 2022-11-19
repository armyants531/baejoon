// 용액  // two pointer
#include <bits/stdc++.h>

using namespace std;

struct closest {
	long long len;
	int low;
	int high;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<long long> arr;
	int low = 0, high = N - 1;
	long long val;
	for (int i = 0; i < N; i++) {
		cin >> val; 
		arr.push_back(val);
	}
	closest info;
	info.len = abs(arr[low] + arr[high]);
	info.low = low;
	info.high = high;
	long long sum;
	while (low < high) { // low 
		sum = arr[low] + arr[high];
		if (sum == 0) { // sum이 0이면 정보 업데이트 후 종료
			info.len = 0;
			info.low = low;
			info.high = high;
			break;
		}
		else if (sum > 0) {
			if (info.len > abs(sum)) { // 두 용액의 특성값 합의 절댓값이 더 작은 경우에 갱신
				info.len = abs(sum);
				info.low = low;
				info.high = high;
			}
			high--; // high를 한 칸 감소 
		}
		else { // sum < 0
			if (info.len > abs(sum)) {
				info.len = abs(sum);
				info.low = low;
				info.high = high;
			}
			low++; // low를 한 칸 증가
		}
	}
	cout << arr[info.low] << " " << arr[info.high] << "\n";

	return 0;
}