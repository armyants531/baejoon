#include <bits/stdc++.h>

using namespace std;

struct Data {
	string S;
	int I;
	int D;
};

bool compare(Data a, Data b) {
	return a.I < b.I;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	cin >> N;
	vector<Data> arr;
	for (int i = 0; i < N; i++) {
		string S;
		int I;
		int D;
		cin >> S >> I >> D;
		arr.push_back({ S, I, D });
	}
	char cha;
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < N; i++) {
		cha = arr[i].S[arr[i].D - 1];
		if (cha >= 'a' && cha <= 'z') {
			cha += 'A' - 'a';
		}
		cout << cha;
	}
	cout << "\n";

}