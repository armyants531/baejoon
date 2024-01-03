#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;
using pii = pair<int, int>;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	// 3, 2, E에 가중치 -1, 0, 1 부여 
	// 뒤집었을때 곂치는 것끼리 묶기(a1, aN), (a2, aN-1), ...  
	int a = 0, b = 0, c = 0, d = 0; // 묶음의 가중치 -2, -1, 1, 2 
	// 처음 아름다움
	int val = 0; 
	for (int i = 0; i < N / 2; i++) {
		if (s[i] == '2') {
			if (s[N - 1 - i] == '3') {
				b++;
			}
			else if (s[N - 1 - i] == 'E') {
				c++;
			}
			else {
				val += 2;
			}
		}
		else if (s[i] == '3') {
			if (s[N - 1 - i] == '2') {
				b++;
			}
			else if (s[N - 1 - i] == '3') {
				a++;
			}
			else {
				val += 2;
			}
		}
		else { // s[i] == 'E'
			if (s[N - 1 - i] == '2') {
				c++;
			}
			else if (s[N - 1 - i] == '3') {
				val += 2;
			}
			else {
				d++;
			}
		}
	}
	cout << val << "\n";
	for (int i = 1; i <= K; i++) {
		if (a > 0 && d > 0) {
			val += 4;
			a--;
			d--;
		}
		else if (b > 0 && c > 0) {
			val += 4;
			b--;
			c--;
		}
		else if (b > 0 && d > 0) {
			val += 2;
			b--;
			d--;
			c++; 
		}
		else if (a > 0 && c > 0) {
			val += 2;
			a--;
			c--;
			b++;
		}
		else if (b > 1) {
			val += 2;
			b -= 2;
			a += 2;
		}
		else if (c > 1) {
			val += 2;
			c -= 2;
			d += 2;
		}
		cout << val << "\n";
	}
	
	return 0;
}