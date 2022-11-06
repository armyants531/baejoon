// Counting Inversions // merge sort
// https://eine.tistory.com/entry/%EB%B0%B1%EC%A4%80-10090%EB%B2%88-%EB%AC%B8%EC%A0%9C-Counting-Inversions-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4
// https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/ 참고
#include <iostream>

using namespace std;
typedef long long ll;

int *arr, *tmp;
ll inv_cnt = 0; // inverse 쌍의 개수

void merge(int start, int mid, int end) {
	int i = start; // 왼쪽 배열의 인덱스
	int j = mid; // 오른쪽 배열의 인덱스
	int k = start; // 합친 배열(tmp)의 인덱스
	while ((i <= mid - 1) && (j <= end - 1)) {
		if (arr[i] > arr[j]) {
			tmp[k] = arr[j];
			k++; j++;
			inv_cnt += mid - i; // 왼쪽 배열에 남아있는 원소의 수(mid - i) = inverse 쌍의 수
		}
		else { // arr[i] <= arr[j]	
			tmp[k] = arr[i];
			k++; i++;
		}
	}
	// 남은 왼쪽 배열의 원소를 tmp에 복사
	while (i <= mid - 1) {
		tmp[k] = arr[i];
		k++; i++;
	}
	// 남은 오른쪽 배열의 원소를 tmp에 복사
	while (j <= end - 1) {
		tmp[k] = arr[j];
		k++; j++;
	}
	// 원본 배열에 tmp배열 원소 복사
	for (i = start; i <= end - 1; i++) {
		arr[i] = tmp[i];
	} 
}

void mergeSort(int start, int end) { // [start, end)
	int mid = (start + end) / 2;
	if (start != mid) { // start == mid이면 실행하지 않음
		mergeSort(start, mid); // [start, mid)
		mergeSort(mid, end); // [mid, end)
		merge(start, mid, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	arr = new int[n]();
	tmp = new int[n]();
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mergeSort(0, n); // [0, n)
	cout << inv_cnt << "\n";

	delete[] arr;
	delete[] tmp;
	return 0;
}