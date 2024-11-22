#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int idx = 0;
vector<char> s;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);	
}

struct Frac {
	ll a, b;
	void reduct() {
		ll g = gcd(a, b);
		a /= g;
		b /= g;
	}
};

Frac operator+(const Frac& x, const Frac& y) {
	Frac f = {x.a * y.b + x.b * y.a, x.b * y.b};
	f.reduct();
	return f;
}

Frac operator/(const Frac& x, const Frac& y) {
	Frac f = {x.a * y.b, x.b * y.a};
	f.reduct();
	return f;
}

Frac parse() {
	if (idx >= s.size()) {
		cout << -1 << "\n";
		exit(0);
	}
	char ch = s[idx++];
	if (ch == '(') {
		Frac a = parse();
		Frac b = parse();
		Frac c = parse();
		if (idx >= s.size()) {
			cout << -1 << "\n";
			exit(0);
		}
		char ch = s[idx++];
		if (ch != ')') {
			cout << -1 << "\n";
			exit(0);	
		}
		return a + b / c;
	} else if (ch == ')') {
		cout << -1 << "\n";
		exit(0);
	}
	else {  // number -> change to fraction
		Frac f = {ch - '0', 1};	
		return f;
	} 
}

int main() {
	int n;
	cin >> n;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c != ' ') s.push_back(c);
	}
	Frac ans = parse();
	if (idx != s.size()) {  // check if all parsed
		cout << -1 << "\n";
		exit(0);
	}
	cout << ans.a << " " << ans.b << "\n";
	return 0;
}