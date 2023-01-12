// 찾기  // string  // kmp
// https://ansohxxn.github.io/algorithm/kmp/ 참고
#include <bits/stdc++.h>

using namespace std;

// 인덱스별로 (접두사 = 접미사)의 최대 길이를 구하기(전처리) -> O(M)
vector<int> preset(string P) {
	int M = P.size();
	// partial match table
	vector<int> lps(M); // 실패함수
	int f = 0;
	for (int s = 1; s < M; s++) {
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

// 검색 함수: O(N)
vector<int> KMP(string T, string P) { // 텍스트, 검색어
	int M = P.size();
	int N = T.size();
	vector<int> lps = preset(P); // 전처리
	vector<int> idx; // 검색에 성공한 인덱스 저장
	int j = 0;
	for (int i = 0; i < N; i++) {
		while (j >= 1 && T[i] != P[j]) { // 검색어 첫 글자에서 시작해 검사해야 하는 인덱스에 도달할 때까지 최대 길이의 '접두사 = 접미사' 부분 걸치기 
			j = lps[j - 1]; // 검사 시작점 설정
		}
		if (T[i] == P[j]) { // 일치하면
			if (j != M - 1) { // 검색이 끝나지 않았으면
				j++; // 다음 원소 검사
			}
			else { // 검색 끝, j == M - 1
				idx.push_back(i + 2 - M);  // 인덱스는 1부터 시작: (i + 1) - M + 1
				j = lps[M - 1]; // 검사 시작점 설정
			}
		}
	}
	return idx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string T, P;
	getline(cin, T);
	getline(cin, P);
	vector<int> idx = KMP(T, P);
	cout << idx.size() << "\n";
	for (auto i : idx) {
		cout << i << " ";
	}

	return 0;
}