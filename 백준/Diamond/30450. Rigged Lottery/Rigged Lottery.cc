// K = 3, C = 2일 때 내 티켓이 1 2 1 이면: 1 2 [], 1 [] 1, [] 2 1 -> [] 2 1 [] 1 2 [] -> 2 2 1 1 1 2 2
#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, c;
	cin >> k >> c;
	vector<int> my(k); // my ticket
	for (int i = 0; i < k; i++) cin >> my[i];
	vector<int> fail; // 실패수열
	// 실패수열 생성
	for (int i = 0; i < k; i++) { 
		// 내 티켓의 맨 앞이 아니면 현재 수 앞의 숫자를 넣기 
        if (i != 0) cout << my[i - 1] << " "; 
		// 빈 칸에 해당하는 숫자 채우기
        // c에서 1까지 중에서 my[i]와 다른 것 모두 출력 
        for (int j = 1; j <= c; j++) {
            if (my[i] != j) cout << j << " ";
        }
		// 내 티켓의 맨 뒤가 아니고 이전과 중복이 아니면 현재 수 뒤의 숫자를 출력 
        if (i != k - 1) {
            if (my[i] != my[i + 1]) cout << my[i + 1] << " ";
        }
	}
    cout << "\n";
	return 0;
}