#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C;
	cin >> C;
	bool correct = true;
	vector<int> visited(C + 1);
	int pre = 0;
	vector<int> m(C + 1);
	for (int i = 1; i <= C; i++) {
		cin >> m[i];
		if (i == 1) {
			if (m[i] != 1) correct = false;  
		}
		else if (m[i - 1] < m[i] - 1) {
			correct = false;  
		}
	}	
	if (!correct) {
		cout << -1 << "\n";
	} 
	else {
		for (int i = 1; i <= C; i++) {
			if (m[i - 1] > m[i]) { // if previous num is bigger 
				visited[m[i]]++;
				cout << visited[m[i]] << " ";
			}
			else if (m[i - 1] < m[i]) { // if previous num is smaller
				visited[m[i]] = 1;
				cout << visited[m[i]] << " ";
			}
			else { // m[i - 1] == m[i]
				visited[m[i]]++;
				cout << visited[m[i]] << " ";
			}
		}
	}
	return 0;
}