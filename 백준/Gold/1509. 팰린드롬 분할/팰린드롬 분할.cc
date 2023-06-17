// 팰린드롬 분할  // dp
// https://mangu.tistory.com/78#3.%20%EC%BD%94%EB%93%9C 참고
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool table[2500][2500]; // 팰린드롬 여부 확인 테이블
vector<int> cnt(2501); // cnt[i + 1] : 0 ~ i까지 최소 분할 개수

void palindrome(string s, int n) { // 팰린드롬 여부 확인
	// 1개짜리
	for (int i = 0; i < n; i++) {
		table[i][i] = true;
	}
	// 2개짜리
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			table[i][i + 1] = true;
		} 
	}
	// 3개 이상
	for (int k = 2; k < n; k++) {
		for (int i = 0; i + k < n; i++) {
			if (s[i] == s[i + k] && table[i + 1][i + k - 1]) {
				table[i][i + k] = true;
			}
		}
	}
}

int count(int n) { // 최소 분할 수 세기
	cnt[0] = 0;
	for (int j = 0; j < n; j++) {
		cnt[j + 1] = 2501;
		for (int i = 0; i <= j; i++) {
			if (table[i][j]) {
				cnt[j + 1] = min(cnt[j + 1], cnt[i] + 1); // 
			}
		}
	}
	return cnt[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	palindrome(s, n);
	cout << count(n) << "\n";

	return 0;
}