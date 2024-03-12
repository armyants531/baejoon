#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

vector<string> a;
vector<int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	double M;
	double t;
	cin >> M;
	if (M <= 30) {
		t = M / 2;
	}
	else {
		t = 15 + (M - 30) * 3 / 2; 
	}
	cout << fixed;
	cout.precision(1);
	cout << t << "\n";
	return 0;
}