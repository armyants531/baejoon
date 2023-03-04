#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<string, double> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<string> arr;
	bool del = false;
	for (int i = 0; i < N; i++) {
		string str;
		double num;
		cin >> str >> num;
		if (mp[str] == 0) {
			arr.push_back(str);
		}
		mp[str] += num;
	}
	for (int i = 0; i < arr.size(); i++) {
		int ai = floor(mp[arr[i]] * 1.618);
		for (int j = 0; j < arr.size(); j++) {
			if (i != j && ai == mp[arr[j]]) {
				del = true;
				break;
			}
		}
		if (del) {
			break;
		}
	}
	if (del) {
		cout << "Delicious!" << "\n";
	}
	else {
		cout << "Not Delicious..." << "\n";
	}

	return 0;
}