#include <bits/stdc++.h>
#define int long long

using namespace std;
vector<string> d;

int cnt(vector<char> num) {
	int ans = 0;
	for (int i = 0; i < 366; i++) {
		bool can = true;
		for (int j = 0; j < num.size(); j++) {
			if (d[i].find(num[j]) != string::npos) {
				can = false;
				break;
			}
		}
		if (can) ans++; 
	}
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	for (int i = 1; i <= 31; i++) {
		string s = '1' + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 29; i++) {
		string s = '2' + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 31; i++) {
		string s = '3' + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 30; i++) {
		string s = '4' + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 31; i++) {
		string s = '5' + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 30; i++) {
		string s = '6' + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 31; i++) {
		string s = '7' + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 31; i++) {
		string s = '8' + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 30; i++) {
		string s = '9' + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 31; i++) {
		string s = "10" + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 30; i++) {
		string s = "11" + to_string(i);
		d.push_back(s);
	}
	for (int i = 1; i <= 31; i++) {
		string s = "12" + to_string(i);
		d.push_back(s);
	}
	int T;
	cin >> T;
	while (T--) {
		int a;
		vector<char> num;
		for (int i = 0; i < 10; i++) {
			cin >> a;
			if (a) {
				num.push_back((char)(i + 48));
			} 
		}
		cout << cnt(num) << "\n";
	}
		
	return 0;
}