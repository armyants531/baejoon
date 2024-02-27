#include <bits/stdc++.h> 

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> len(n); // i번째 인덱스에서 끝나는 LIS 길이를 저장하는 리스트
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int max_len = 1;
	for (int i = 0; i < n; i++) {
		len[i] = 1;
		for (int j = 0; j < i; j++) { // i 이전 원소 탐색 
			if (v[i] > v[j]) {
				len[i] = max(len[i], len[j] + 1);
			}
		}
		max_len = max(max_len, len[i]); 
	}
	cout << max_len << "\n";
	
	return 0;
}