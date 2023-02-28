// 롤러코스터  // greedy
// https://www.slideshare.net/Baekjoon/baekjoon-online-judge-2873 참고
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> table;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int R, C;
	string s = "";
	cin >> R >> C;
	table.resize(R, vector<int>(C));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> table[i][j];
		}
	}
	if (R % 2 == 1) { // 홀수 행 (ㄹ)
		for (int i = 0; i < R / 2; i++) {
			for (int j = 1; j < C; j++) s += 'R';
			s += 'D';
			for (int j = 1; j < C; j++) s += 'L';
			s += 'D';
		}
		for (int i = 1; i < C; i++) s += 'R';
	}
	else if (C % 2 == 1) { // 홀수 열
		for (int i = 0; i < C / 2; i++) {
			for (int j = 1; j < R; j++) s += 'D';
			s += 'R';
			for (int j = 1; j < R; j++) s += 'U';
			s += 'R';
		}
		for (int i = 1; i < R; i++) s += 'D';
	}
	else { // 짝수 행, 짝수 열
		// 체스판에서 방문하지 않을 검은 칸 선택
		int min_r = -1;
		int min_c = -1;
		int min_val = 1001;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if ((i + j) % 2 == 1) {
					if (min_val > table[i][j]) {
						min_val = table[i][j];
						min_r = i;
						min_c = j;
					} 
				}
			}
		}
		string s1 = ""; // 두 행 윗부분
		string s2 = ""; // 불포함 되는 검은 칸이 있는 두 행
		string s3 = ""; // 두 행 아랫부분
		// 두 행 윗부분
		for (int i = 0; i < min_r / 2; i++) {
			for (int j = 1; j < C; j++) s1 += 'R';
			s1 += 'D';
			for (int j = 1; j < C; j++) s1 += 'L';
			s1 += 'D';
		}
		// 두 행 부분
		int x = 0;
		int y = 0;
		int X = min_r % 2;
		int Y = min_c;
		while (true) {
			x++; // down
			if (x == X && y == Y) {
				y++;
				s2 += 'R';
				s2 += 'D';
			}
			else {
				s2 += 'D';
			}
			if (x == 1 && y == C - 1) break; // 종료
			
			y++; // right
			s2 += 'R';
			if (x == 1 && y == C - 1) break; // 종료

			x--; // up
			if (x == X && y == Y) {
				x++;
				y++;
				s2 += 'R';
				if (x == 1 && y == C - 1) break; // 종료
				x--;
				s2 += 'U';
			}
			else {
				s2 += 'U';
			}
			y++; // right
			s2 += 'R';
			if (x == 1 && y == C - 1) break; // 종료
		}
		// 두 행 아랫부분
		for (int i = 0; i < (R - 1 - min_r) / 2; i++) {
			s3 += 'D';
			for (int j = 1; j < C; j++) s3 += 'L';
			s3 += 'D';
			for (int j = 1; j < C; j++) s3 += 'R';
		}
		/*
		cout << "s1 : " << s1 << "\n";
		cout << "s2 : " << s2 << "\n";
		cout << "s3 : " << s3 << "\n";
		*/
		s = s1 + s2 + s3;
	}
	cout << s << "\n";
}