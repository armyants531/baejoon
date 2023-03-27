// 문자열 제곱  // KMP
#include <bits/stdc++.h>

using namespace std;

// 인덱스별로 (접두사 = 접미사)의 최대 길이를 구하기(전처리) -> O(M)
vector<int> preset(string P) {
	int M = P.size();
	// 실패함수(Longest Prefix Suffix)
	vector<int> lps(M); // lps[i] = 처음부터 현재 인덱스(i)까지의 lps 길이
	int s = 0;
	for (int f = 1; f < M; f++) {
		// 최대 길이의 '접두사 = 접미사' 부분 걸치기
		while (s >= 1 && P[f] != P[s]) {
			s = lps[s - 1];
		}
		if (P[f] == P[s]) {
			s++; // 다음으로 넘어가서 비교
			lps[f] = s;
		}
	}
	return lps;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	while (s != ".") {
		int M = s.size();
		vector<int> lps = preset(s);
		// M - lps[M - 1] 크기의 문자열이 반복이 안되는 경우 : ex) ababa 는 ab 반복으로는 안됨-> '문자열 길이 / 반복 길이' 값이 정수인가?
		if (M % (M - lps[M - 1]) == 0) {
			cout << M / (M - lps[M - 1]) << "\n";
		}
		else {
			cout << 1 << "\n";
		}
		cin >> s;
	}

	return 0;
}