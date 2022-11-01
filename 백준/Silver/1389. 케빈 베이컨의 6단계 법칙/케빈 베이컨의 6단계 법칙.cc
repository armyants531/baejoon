// 케빈 베이컨의 6단계 법칙
// 플로이드-워셜(Floyd-Warshall) 알고리즘
#include <iostream>
#include <queue>
#include <algorithm>

#define INF 101;
using namespace std;

int adj[101][101] = { 0, }; // 인접 행렬
int dist[101][101]; // 최단 거리 배열
int kevin_bacon[101]; // 케빈 베이컨의 수 배열

void bfs() {

}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	// init dist
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) 
				dist[i][j] = 0;
			else if (adj[i][j] != 0) 
				dist[i][j] = adj[i][j];
			else 
				dist[i][j] = INF;
		}
	}
	// mid: 중간 노드의 번호
	for (int mid = 1; mid <= N; mid++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);
			}
		}
	}
	
	int min_num = 4950; // 1+2+...+99 (케빈 베이컨의 수 중 최대값)
	int min_people = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			kevin_bacon[i] += dist[i][j];
		}
		if (min_num > kevin_bacon[i]) {// 더 작은 경우에 바꿈
			min_num = kevin_bacon[i];
			min_people = i;
		}
	}

	cout << min_people << "\n";
}