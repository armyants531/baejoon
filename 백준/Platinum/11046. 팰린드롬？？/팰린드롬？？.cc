#include <bits/stdc++.h>
using namespace std;

int N;
int s[2000001];
int A[2000001];

void manacher() {
	int r = 0; 
	int p = 0;
	for (int i = 0; i < N; i++) {
		// A[i]의 초기값 설정
		if (i <= r) A[i] = min(r - i, A[2 * p - i]);
		else A[i] = 0;
		// s[i - A[i] - 1] != s[i + A[i] + 1]가 되기 전까지 A[i] 값 증가
		while ((i - A[i] - 1 >= 0 && i + A[i] + 1 < N) &&
			(s[i - A[i] - 1] == s[i + A[i] + 1])) A[i]++;
		// r, p update
		if (r < i + A[i]) {
			r = i + A[i];
			p = i;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		s[i * 2] = -1;
		cin >> s[i * 2 + 1];
	}
	s[N * 2] = -1;
	N = N * 2 + 1;
	
	manacher();

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;
		if (A[S + E - 1] >= E - S + 1) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}

	return 0;
}