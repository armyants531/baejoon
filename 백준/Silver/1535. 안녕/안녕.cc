#include <bits/stdc++.h>

using namespace std;

vector<int> L(21);
vector<int> J(21);
vector<vector<int>> t(21, vector<int>(101));

int knapsack(int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 100; j++) {
			if (j-L[i] >= 1) {
				t[i][j] = max(t[i-1][j], J[i] + t[i-1][j-L[i]]);
			}
			else {
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[N][100];
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L[i+1];
	}
	for (int i = 0; i < N; i++) {
		cin >> J[i+1];
	}
	
	cout << knapsack(N) << "\n"; 
	/***
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= 100; j++) {
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}
	***/
	return 0;
}