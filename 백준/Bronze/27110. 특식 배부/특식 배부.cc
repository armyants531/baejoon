#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int A, B, C;
	cin >> A >> B >> C;
	cout << min(A, N) + min(B, N) + min(C, N) << "\n";

	return 0;
}