// 가장 긴 팰린드롬 부분 문자열  // dp  // Manacher's Algorithm
// https://www.crocus.co.kr/1075 참고
// 10000이상의 길이를 가진 문자열의 부분 문자열 -> O(n)에 구하기
// A[i] : i번째 문자를 중심으로 하는 가장 긴 회문의 반지름 크기
#include <bits/stdc++.h>

using namespace std;

vector<int> A;

void manacher(string s, int n) {
	// r: 각 인덱스에 대해 회문이 될 수 있는 최대 범위  
	// p: r이 형성되는 중심점
	int r = 0; // r = max(j + A[j]) (for any j < i)
	int p = 0; // p = j_max, r = p + A[p]
	for (int i = 0; i < n; i++) {
		// A[i]의 초기값 설정
		if (i > r) {
			A[i] = 0;
		}
		else { // i <= r
			A[i] = min(r - i, A[2 * p - i]); // 2 * p - i: p에 대해 i와 대칭인 점
		}
		// s[i - A[i] - 1] != s[i + A[i] + 1]가 되기 전까지 A[i] 값 증가
		while (i - A[i] >= 1 && i + A[i] < n - 1 && s[i - A[i] - 1] == s[i + A[i] + 1]) {
			A[i]++;
		}
		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	string s2 = "";
	int n;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		s2 += '*';
		s2 += s[i];
	}
	s2 += '*';
	int len = n * 2 + 1;
	A.resize(len + 1);
	manacher(s2, len);
	int max_len = 0;
	for (int i = 0; i < len; i++) {
		max_len = max(max_len, A[i]);
	}
	cout << max_len << "\n";

	return 0;
}