// 파일 합치기  // DP  // 최소행렬곱셈법
#include <bits/stdc++.h>

using namespace std;

vector<int> preSum(501, 0); // 구간합을 구할 때 사용
vector<vector<int>> table;
vector<int> cost(501); 
int MAX = 150000000; // 충분히 크게 해야함 10000 * K * log(K)

// s부터 e까지 파일을 합치는데 드는 최소 비용
int memo(int s, int e) { // 구간의 start, end
	if (table[s][e] != -1) {
		return table[s][e];
	}
	else if (s == e) { // 원소 1개
		return 0;
	}
	else {
		table[s][e] = MAX;
		int interval_sum = preSum[e] - preSum[s - 1]; // s ~ e의 합
		for (int i = s; i < e; i++) {
			table[s][e] = min(table[s][e], memo(s, i) + memo(i + 1, e));
		}
		table[s][e] += interval_sum;
		return table[s][e];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int K;
		cin >> K;
		table.resize(K + 1, vector<int>(K + 1, -1));
		for (int j = 1; j <= K; j++) {
			int c;
			cin >> c;
			cost[j] = c;
			preSum[j] = preSum[j - 1] + c;
		}
		cout << memo(1, K) << "\n";
		table.clear(); // table 초기화(중요!)
		/*
		for (int j = 1; j <= K; j++) {
			for (int k = 1; k <= K; k++) {
				cout.width(5);
				cout << table[j][k] << " ";
			}
			cout << "\n";
		}
		*/
	}

	return 0;
}