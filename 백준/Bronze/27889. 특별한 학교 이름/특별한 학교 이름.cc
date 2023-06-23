#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	if (s == "NLCS") {
		cout << "North London Collegiate School" << "\n";
	}
	else if (s == "BHA") {
		cout << "Branksome Hall Asia" << "\n";
	}
	else if (s == "KIS") {
		cout << "Korea International School" << "\n";
	}
	else {
		cout << "St. Johnsbury Academy" << "\n";
	}
	
	return 0;
}