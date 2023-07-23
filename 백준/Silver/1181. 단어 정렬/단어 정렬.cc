#include <bits/stdc++.h>
#define int long long

using namespace std;

struct compare {
	bool operator() (const string &a, const string &b) const {
		if (a.size() == b.size()) {
			return a < b;
		}
		return a.size() < b.size();
	} 
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	set<string, compare> arr;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		arr.insert(s);			
	}
	for (set<string>::iterator it = arr.begin(); it != arr.end(); it++) {
		cout << *it << "\n";
	}
	
	return 0;
}