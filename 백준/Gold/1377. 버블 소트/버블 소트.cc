// 버블 소트
// 몇 번째 수행에서 버블 정렬이 완료되는지 알면 여기에 1을 더한 값이 답이다.
// 이는 1 번째 수 부터 마지막 수까지 정렬이 끝난 후 왼쪽으로 이동한 횟수 중 
// 최댓값에 1을 더한 값으로 생각할 수 있다(한 사이클 당 각 수의 최대 왼쪽 이동 횟수는 1이기 때문).
#include <iostream>
#include <algorithm> // sort
#include <vector>
using namespace std;

typedef struct ELEMENT {
	int val;
	int init_i;
} element;

bool sortData(const element& a, const element& b) {
	if (a.val < b.val) // val 기준 오름차순 정렬
		return true;
	else if (a.val == b.val) { // val이 같으면
		if (a.init_i < b.init_i) // 처음 인덱스 기준 오름차순 정렬
			return true;
	}
	return false;
}

int main() {
	int N;
	cin >> N;
	vector<element> A(N);
	for (int i = 0; i <= N - 1; i++) {
		element e;
		e.init_i = i;
		cin >> e.val;
		A[i] = e;
	}

	sort(A.begin(), A.end(), sortData);

	int max_diff = A[0].init_i;
	for (int i = 1; i <= N - 1; i++) {
		int diff = A[i].init_i - i; // 인덱스 차이 구하기(처음 i - 나중 i)
		if (max_diff < diff) {
			max_diff = diff;
		}
	}
	cout << max_diff + 1 << "\n";

	return 0;
}