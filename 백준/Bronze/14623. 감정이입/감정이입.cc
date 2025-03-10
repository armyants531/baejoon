#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string B1, B2;
	cin >> B1 >> B2;
	ll b1 = 0, b2 = 0;
	ll p = 1;
	for (int i = B1.size() - 1; i >= 0; i--) {
		b1 += (int)(B1[i] - '0') * p;
		p *= 2;	
	}
	p = 1;
	for (int i = B2.size() - 1; i >= 0; i--) {
		b2 += (int)(B2[i] - '0') * p;
		p *= 2;	
	}
	//cout << b1 << " " << b2 << "\n"; 
	ll c = b1 * b2;
	//cout << c << "\n";
	string s = "";
	while (c > 1) {
		string ch = to_string(c % 2);
		s = ch + s;	
		c /= 2;	
	}
	s = to_string(c) + s; 
	cout << s << "\n";
}