// LCS 4  // dp // LIS
// https://travelbeeee.tistory.com/490 참고
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(100000);
	vector<int> B(100000);
	vector<int> AB(100000);
	int p;
	for (int i = 0; i < N; i++) {
		cin >> p; 
		A[p - 1] = i; // 입력받는 값을 인덱스라고 생각하고 A배열을 생성
	}
	for (int i = 0; i < N; i++) {
		cin >> p;
		B.push_back(p - 1);
		AB[i] = A[p - 1]; // A[B[i]]
	}

	// AB[i]의 LIS 구하기 
	vector<int> vec;
	int len = 0;
	vec.push_back(-1); // 처음에 입력 가능한 수열의 원소보다 작은 수를 삽입(처음 원소를 항상 삽입하기 위해)
	for (int i = 0; i < N; i++) {
		int val = AB[i];
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