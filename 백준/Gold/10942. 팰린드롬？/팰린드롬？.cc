// 팰린드롬?  // dp  // memoization
#include <bits/stdc++.h>

using namespace std;

int table[2000][2000]; // 팰린드롬 여부 확인 테이블
vector<int> arr; // 수열 저장

int palindrome(int S, int E) {
	int& ret = table[S][E]; // table[S][E] 값을 참조
	if (ret != -1) { // 이미 적혀 있으면
		return ret;
	}
	if (arr[S] != arr[E]) { // 양 끝이 다르면
		return ret = 0;
	}
	else { // 양 끝이 같으면
		if (S + 2 == E) { // 판별해야 하는 수가 1개만 남으면
			return ret = 1;
		}
		else if (S + 1 == E) { // 판별해야 하는 수가 0개 남으면
			return ret = 1;
		}
		else { // 판별해야 하는 수가 2개 이상이면 
			return ret = palindrome(S + 1, E - 1); // 계속 판별 진행 
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(table, -1, sizeof(table)); // -1로 초기화
	int N;
	cin >> N;
	int A;
	for (int i = 0; i < N; i++) {
		cin >> A;
		arr.push_back(A);
	}
	int M;
	cin >> M;
	int S, E;
	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		if (S == E) {
			cout << 1 << "\n";
		}
		else {
			cout << palindrome(S - 1, E - 1) << "\n";
		}
	}
	return 0;
}