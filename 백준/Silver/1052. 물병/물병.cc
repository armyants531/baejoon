#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	if (N <= K) {
		cout << 0 << "\n";
	}
	else {
		int pow2 = 1;
		while (N >= pow2) {
			pow2 *= 2;
		}
		pow2 /= 2;
		int cnt = 0;
		int p = pow2; 
		while (p) {
			if ((N & p) != 0) {
				cnt++;
			}
			p /= 2;
		}
		if (cnt <= K) {
			cout << 0 << "\n";	
		}
		else {
			cnt = 0;
			int num = 0; // 목표 물병 수 
			while (cnt < K) {
				if ((N & pow2) != 0) {
					num += pow2;
					cnt++;
				}
				pow2 /= 2;
			}
			num += pow2 * 2;			
			cout << num - N << "\n";
		}
	}
	return 0;
}