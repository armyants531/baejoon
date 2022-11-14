// ACM Craft  // dp  // graph  // Topological sort
// https://m.blog.naver.com/kks227/220620723528 참고
#include <bits/stdc++.h>

using namespace std;

long long solve(int N, int W, vector<long long> D, vector<int> pre_num, vector<int> suc_list[]) {
	// 해당 건물 건설을 시작하기 위해 필요한 최소 시간 리스트 
	vector<long long> total_time(1000, 0);
	queue<int> que;
	// 선행자가 없는 노드 삽입
	for (int j = 0; j < N; j++) { // 0 ~ N-1
		if (pre_num[j] == 0) {
			que.push(j);
		}
	}
	// W번 건물의 선행자가 없을 때까지 진행
	while (pre_num[W - 1] != 0) {
		int n = que.front();
		que.pop();
		// 노드 n의 후행자 리스트 탐색
		for (int i = 0; i < suc_list[n].size(); i++) {
			int suc_node = suc_list[n][i];
			pre_num[suc_node]--; // 후행자의 선행자 개수 - 1
			// 건설 시작 최소 시간 리스트 업데이트
			// (n번 건물 짓기 시작하는데 걸린 시간 + n번 건물 짓는데 걸리는 시간)과 다른 경로로 진입해 구한 건설 최소 시간을 비교
			total_time[suc_node] = max(total_time[n] + D[n], total_time[suc_node]);
			if (pre_num[suc_node] == 0) { // 선행자 개수가 0인 노드가 생기면
				que.push(suc_node);
			}
		}
	}

	long long min_time = total_time[W - 1] + D[W - 1];
	return min_time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, K, W;
		cin >> N >> K;
		vector<long long> D(1000, 0); // time list
		vector<int> pre_num(1000, 0); // number of predecessor(선행자 갯수)
		vector<int> suc_list[1000]; // list of successor(후행자 리스트)
		for (int j = 0; j < N; j++) {
			cin >> D[j];
		}
		for (int j = 0; j < K; j++) {
			int X, Y;
			cin >> X >> Y;
			suc_list[X - 1].push_back(Y - 1); // X - 1인덱스의 후행자 리스트에 Y - 1 추가
			pre_num[Y - 1]++; // Y의 선행자 갯수 1 증가
		}
		cin >> W; // 승리하기 위한 건물 번호(나중에 -1 해줌)

		cout << solve(N, W, D, pre_num, suc_list) << "\n";
	}
	return 0;
}