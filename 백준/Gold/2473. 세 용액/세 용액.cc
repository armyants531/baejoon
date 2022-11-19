// 세 용액  // two pointer
#include <bits/stdc++.h>

using namespace std;

struct closest {
	long long sum;
	int low;
	int mid;
	int high;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	vector<long long> arr;
	int low = 0, high = N - 1;
	int mid = 1;
	long long val;
	for (int i = 0; i < N; i++) {
		cin >> val;
		arr.push_back(val);
	}
	// 오름차순 정렬
	sort(arr.begin(), arr.end());

	closest info;
	info.sum = abs(arr[low] + arr[mid] + arr[high]);
	info.low = low;
	info.mid = mid;
	info.high = high;
	long long sum = 0;
	for (int i = 0; i < N - 2; i++) {
		low = i;
		mid = i + 1;
		high = N - 1;
		while (mid < high) {
			sum = arr[low] + arr[mid] + arr[high];
			if (sum == 0) { // sum이 0이면 정보 업데이트 후 종료
				info.sum = 0;
				info.low = low;
				info.mid = mid;
				info.high = high;
				break;
			}
			else if (sum > 0) {
				long long abs_sum = abs(sum);
				if (info.sum > abs_sum) { // 두 용액의 특성값 합의 절댓값이 더 작은 경우에 갱신
					info.sum = abs_sum;
					info.low = low;
					info.mid = mid;
					info.high = high;
				}
				high--; // high를 한 칸 감소 
			}
			else { // sum < 0
				long long abs_sum = abs(sum);
				if (info.sum > abs_sum) {
					info.sum = abs_sum;
					info.low = low;
					info.mid = mid;
					info.high = high;
				}
				mid++; // mid를 한 칸 증가
			}
		}
	}
	std::cout << arr[info.low] << " " << arr[info.mid] << " " << arr[info.high] << "\n";

	return 0;
}