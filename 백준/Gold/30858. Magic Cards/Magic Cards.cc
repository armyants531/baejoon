#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, M, F;
	cin >> N >> K >> M >> F;
	vector<bitset<100>> v(N + 1); // 숫자별로 어떤 카드뭉치에 있는지 여부   
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
		 	v[a][i] = 1;
		}	
	}	
	vector<bitset<100>> str(F);
	for (int i = 0; i < F; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < K; j++) {
			if (s[j] == 'Y') {
				str[i][j] = 1;
			}	
		}
	}
	unordered_map<bitset<100>, int> mp; // 답지 생성(bitset input -> number output) 
	for (int i = 1; i <= N; i++) {
		bitset<100> bit = v[i];
		if (mp[bit] != 0) { // 중복된 답: 문자열로 답을 알 수 없음 
			mp[bit] = -1;
		}
		else {
			//cout << s << " " << i << "\n";
			mp[bit] = i;
		}
	}
	// 출력  
	for (int i = 0; i < F; i++) {
		if (mp[str[i]] > 0) {
			cout << mp[str[i]] << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	
	return 0;
}