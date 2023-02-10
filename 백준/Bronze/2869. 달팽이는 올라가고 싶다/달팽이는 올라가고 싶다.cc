#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll A, B, V;
	cin >> A >> B >> V;
	ll h = A - B;
	ll day = ceil((double)(V - A) / h);
	day++;
	cout << day << "\n";
	
	return 0;
}