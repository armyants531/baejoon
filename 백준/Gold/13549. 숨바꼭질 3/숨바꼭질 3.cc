// 숨바꼭질 3  // dijkstra
// 현재 위치가 50001 이상이고 동생이 100000에 있을 때 -> 뺀 다음에 * 2하는 것이 효율적
// 따라서 100000이하의 위치만 생각
#include <bits/stdc++.h>
#define INF 1000001

using namespace std;

// start = 시작 위치, end = 끝 위치
int dijkstra(int start, int end) {
	vector<int> cost(100001, INF); // cost를 저장할 리스트
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // lower distance has priority
	cost[start] = 0; // start node distance = 0
	pq.push({ 0, start }); // {cost, node}
	while (!pq.empty()) {
		// current node info 
		int curr_node = pq.top().second;
		int curr_cost = pq.top().first;
		pq.pop(); // pop the current node
		int next_node = curr_node * 2;
		if (next_node <= 100000) {
			// update min cost
			if (cost[next_node] > curr_cost) {
				cost[next_node] = curr_cost;
				// push the updated node
				pq.push({ curr_cost, next_node });
			}
		}
		next_node = curr_node + 1;
		if (next_node <= 100000) {
			if (cost[next_node] > curr_cost + 1) {
				cost[next_node] = curr_cost + 1;
				pq.push({ curr_cost + 1, next_node });
			}
		}
		next_node = curr_node - 1;
		if (next_node >= 0) {
			if (cost[next_node] > curr_cost + 1) {
				cost[next_node] = curr_cost + 1;
				pq.push({ curr_cost + 1, next_node });
			}
		}
	}
	return cost[end];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;
	cout << dijkstra(A, B) << "\n";

	return 0;
}