// 좌표 압축
// 원본 배열의 복사 배열을 만들고 이를 정렬한 후 중복된 값을 제거한다.
#include <iostream>
#include <algorithm> // lower_bound, unique, sort
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<long long> arr(n);
	vector<long long> sort_arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sort_arr[i] = arr[i];
	}
	sort(sort_arr.begin(), sort_arr.end()); // 오름차순 정렬
	sort_arr.erase(unique(sort_arr.begin(), sort_arr.end()), sort_arr.end()); // 중복값 제거

	for (int i = 0; i < n; i++) {
		// lower_bound(시작값, 종료값, key 값): 처음부터 탐색하여 key 값과 같거나 더 큰 값을 반환(반환형: iterator)해주는 함수 
		cout << lower_bound(sort_arr.begin(), sort_arr.end(), arr[i]) - sort_arr.begin() << " "; // .begin()을 빼면 인덱스 리턴
	}
	cout << "\n";

	return 0;
}