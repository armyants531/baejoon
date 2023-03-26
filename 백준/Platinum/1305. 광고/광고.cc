// 광고  // string  // KMP
#include <bits/stdc++.h>

using namespace std;

// 인덱스별로 (접두사 = 접미사)의 최대 길이를 구하기
vector<int> preset(string P) {
	int M = P.size();
	// partial match table
	vector<int> lps(M); // 실패함수(Longest Prefix Suffix)
	int f = 0; // f : first idx
	for (int s = 1; s < M; s++) { // s : second idx
		while (f >= 1 && P[f] != P[s]) {
			f = lps[f - 1]; // 검사 시작점 설정: 최대 길이의 '접두사 = 접미사' 부분 걸치기
		}
		if (P[f] == P[s]) {
			f++; // increase first idx
			lps[s] = f; // save 'index + 1'
		}
	}
	return lps;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int L;
	cin >> L;
	string s;
	cin >> s;
	vector<int> lps = preset(s);
	// L - (접두사 == 접미사 최대 길이) -> 반복되는 광고의 가장 짧은 길이
	cout << L - lps[L - 1] << "\n";
	return 0;
}