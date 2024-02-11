#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

int N, K, M;
vector<int> A, D;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K >> M;
	A.resize(N);
	D.resize(M);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> D[i];
	}
	sort(A.begin(), A.end(), greater<int>()); // 소켓의 수가 많은 멀티탭 순으로  
	sort(D.begin(), D.end(), greater<int>()); // 전자기기 거리제한이 널널한 순으로 
	int low = 1, high = M;
	int max_x = 0;
	while (low <= high) {
		int x = (low + high) / 2;
		vector<int> dev(x); // x개의 장치 선택 
		for (int i = 0; i < x; i++) {
			dev[x-1-i] = D[i];
		}
		int cnt = K; // 소켓의 수
		int idx = 0; // 전자기기 인덱스
		int idx2 = 0; // 멀티탭 인덱스 
		int d = 0; // 콘센트로부터 거리
		bool can = false;
		while (cnt > 0) { // 소켓 남음  
			while (dev[idx] == d) { // 전자기기 거리제한이 현재 거리와 동일 
				cnt--; // 전자기기를 소켓에 연결 
				idx++;	
				if (cnt == 0 || idx == x) break;
			}
			int tmp = cnt;
			while (tmp-- && idx2 < N) { // 큰 것부터 멀티탭 연결
				cnt+=(A[idx2]-1); // 소켓 수 갱신  
				idx2++;
			}
			d++; // 거리 갱신 		
			if (idx == x) { // 성공 
				can = true;
				break;
			}
			if (idx2 == N) { // 멀티탭 소진 
				if (cnt >= (x-idx)) {
					can = true;	
				}  
				break; 
			}
		}
		if (can) {
			low = x+1;
			max_x = max(max_x, x);
		}
		else {
			high = x-1;
		}
	}	
	cout << max_x << "\n"; 
	return 0;
}