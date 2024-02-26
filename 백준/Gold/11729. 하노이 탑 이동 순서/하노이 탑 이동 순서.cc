#include <bits/stdc++.h> 

using namespace std;
// 옮겨야 할 원판 수, start, other, end
// s->e로 n번째 원판 옮김 
void rec(int N, int s, int o, int e) {
	if (N == 1) {
		cout << s << " " << e << "\n";
		return; 		
	}
	rec(N-1, s, e, o); // s에서 o으로 n-1개 원판 옮김 
	cout << s << " " << e << "\n"; // n번째 원판을 s->e 
	rec(N-1, o, s, e); // o에서 e로 n-1개 원판 옮김 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int K = (int)pow(2, N) - 1;
	cout << K << "\n";
	rec(N, 1, 2, 3);
	
	return 0;
}