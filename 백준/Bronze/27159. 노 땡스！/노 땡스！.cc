#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N; 
	cin >> N;
	int A;
	cin >> A;
	int sum = A;
	for (int i = 1; i < N; i++) {
		int a;
		cin >> a;
		if (A + 1 == a) {
			A = a;
		}
		else {
			sum += a;
			A = a;
		}
	}
	cout << sum << "\n";
}