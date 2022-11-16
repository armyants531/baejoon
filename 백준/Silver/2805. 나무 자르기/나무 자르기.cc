// 나무 자르기  // https://www.acmicpc.net/blog/view/109#comments 참고
#include <bits/stdc++.h>

using namespace std;

vector<long long> tree(1000000);
// mid 높이에 절단기 설치 시 M 이상의 나무를 얻을 수 있는지 여부를 구하여 리턴
bool check(int mid, int N, int M) {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		if (tree[i] > mid) {
			sum += tree[i] - mid;
		}
	}
	if (sum >= M) {
		return true;
	}
	else {
		return false;
	}
}

int binary_search(int low, int high, int N, int M) {
	while (low < high - 1) { // low와 high사이에 칸이 존재할 때까지
		int mid = (low + high) / 2;
		if (check(mid, N, M)) // mid 높이에서 충분한 나무를 얻을 수 있으면 
			low = mid; // 높이 증가
		else
			high = mid; // 높이 하락
	}
	// low == high - 1 일 때
	return low; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tree[i]; 
	}
	// binary search
	int low = 0, high = 1000000000; // 나무의 최저, 최대 높이로 설정
	cout << binary_search(low, high, N, M) << "\n";

	return 0;
}