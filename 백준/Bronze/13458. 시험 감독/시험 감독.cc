#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	} 
	int B, C;
	cin >> B >> C;
	ll cnt = 0;
	for (int i = 0; i < N; i++) {
		int p = A[i];
		if (p > B) {
			p -= B;
			cnt += ceil((double)p / C) + 1;
		}
		else {
			cnt++;
		}	
	}
	cout << cnt << "\n";
}