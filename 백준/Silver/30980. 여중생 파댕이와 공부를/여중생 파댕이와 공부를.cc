#include <bits/stdc++.h>

using namespace std;

vector<string> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	a.resize(3 * N);
	for (int i = 0; i < 3 * N; i++) {
		cin >> a[i]; 
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// "문자열".substr(startIndex, length);
			string str_x = a[3 * i + 1].substr(8 * j + 1, 1);
			string str_y = a[3 * i + 1].substr(8 * j + 3, 1);
			int x = stoi(str_x);
			int y = stoi(str_y);
			int z;
			string str_z;
			if (a[3 * i + 1][8 * j + 6] == '.') {
				str_z = a[3 * i + 1].substr(8 * j + 5, 1);
				z = stoi(str_z);
				if (x + y == z) {
					for (int k = 1; k <= 5; k++) {
						a[3 * i][8 * j + k] = '*';
					}
					a[3 * i + 1][8 * j] = '*';
					a[3 * i + 1][8 * j + 6] = '*';
					for (int k = 1; k <= 5; k++) {
						a[3 * i + 2][8 * j + k] = '*';
					}
				}
				else {
					a[3 * i][8 * j + 3] = '/';	
					a[3 * i + 1][8 * j + 2] = '/';
					a[3 * i + 2][8 * j + 1] = '/';			
				}
			}
			else {
				str_z = a[3 * i + 1].substr(8 * j + 5, 2);
				z = stoi(str_z);
				if (x + y == z) {
					for (int k = 1; k <= 6; k++) {
						a[3 * i][8 * j + k] = '*';
					}
					a[3 * i + 1][8 * j] = '*';
					a[3 * i + 1][8 * j + 7] = '*';
					for (int k = 1; k <= 6; k++) {
						a[3 * i + 2][8 * j + k] = '*';
					}
				}
				else {
					a[3 * i][8 * j + 3] = '/';	
					a[3 * i + 1][8 * j + 2] = '/';
					a[3 * i + 2][8 * j + 1] = '/';			
				}
			}		
		}
	}
	for (int i = 0; i < 3 * N; i++) {
		cout << a[i] << "\n"; 
	}
	
	return 0;
}