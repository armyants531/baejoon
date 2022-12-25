// 개미굴  // string  // set
// https://cocoon1787.tistory.com/809 참고
#include <bits/stdc++.h>

using namespace std;

set<string> tree; // 중복값 제거, 정렬 기능 있음

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		string temp = "";
		for (int j = 0; j < K; j++) {
			string str;
			cin >> str;
			temp += " " + str;
			tree.insert(temp);
		}
	}
	for (auto i : tree) {
		stringstream ss(i);  // 공백을 기준으로 문자열을 자름
		string s;
		vector<string> v;
		while (ss >> s) {
			v.push_back(s);
		}
		for (int i = 0; i < v.size() - 1; i++) {
			cout << "--" << "";
		}
		cout << v[v.size() - 1] << "\n";
	}
	return 0;
}