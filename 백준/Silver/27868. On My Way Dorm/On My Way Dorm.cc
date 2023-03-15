#include <bits/stdc++.h>

using namespace std;

vector<int> arr(100001);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int N, S;
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	string s;
	cin >> s;
  for (int i = s.size() - 1; i >= 0; i--) {
    cout << s[i] << "";
  }
}