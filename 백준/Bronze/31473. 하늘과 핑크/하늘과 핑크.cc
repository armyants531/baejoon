#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int sumA = 0;
	int sumB = 0;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		sumA += A; 
	}
	for (int i = 0; i < N; i++) {
		int B;
		cin >> B;
		sumB += B;
	}
	cout << sumB << " " << sumA << "\n";
	
	return 0;
}