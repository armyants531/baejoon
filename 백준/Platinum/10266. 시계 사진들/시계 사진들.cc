// Clock Pictures  // KMP
// 시계를 360000 사이즈의 문자열로 생각하고 
// 하나의 시계를 2 번 반복하여 kmp 알고리즘 수행
#include <bits/stdc++.h>

using namespace std;

vector<int> degree1(720000);
vector<int> degree2(360000);

vector<int> preset(vector<int> P) {
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
vector<int> KMP(vector<int> T, vector<int> P) { // 텍스트, 검색어
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
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a;
		degree1[a] = 1;
		degree1[a + 360000] = 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> b;
		degree2[b] = 1;
	}
	vector<int> lps = preset(degree2);
	vector<int> idx = KMP(degree1, degree2);
	if (idx.size() == 0) cout << "impossible" << "\n";
	else cout << "possible" << "\n";
	return 0;
}