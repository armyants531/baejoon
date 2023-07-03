#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double sum;
	cin >> sum;
	sum = min(sum, 1.0);
	cout << fixed;
	cout.precision(12);
	cout << (sum / 2.0) * (sum / 2.0) << "\n";
	
	return 0;	
}