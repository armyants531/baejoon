// 가장 긴 증가하는 부분 수열 2  // binary search  // LIS
// http://jason9319.tistory.com/113?category=670441 참고
#include <bits/stdc++.h>

using namespace std;

vector<int> vec;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, len = 0;
	cin >> N;
	vec.push_back(0); // 처음에 입력 가능한 수열의 원소보다 작은 수를 삽입(처음 원소를 항상 삽입하기 위해)
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		if (vec.back() >= val) {
			// lower_bound: 찾으려는 val(key) 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지를 리턴(반환형: iterator)
			int lb = lower_bound(vec.begin(), vec.end(), val) - vec.begin();  // 인덱스 구하기
			vec[lb] = val; // 최적의 위치에 val 삽입
		}
		else { // vec.back() < val 이면  
			vec.push_back(val); // 삽입
			len++; // 길이 증가
		}
	}
	cout << len << "\n";

	return 0;
}