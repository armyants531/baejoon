// 숨바꼭질
// bfs: 동생을 못 찾으면 X-1, X+1, 2*X를 방문 여부 확인 후 queue에 넣기 
#include <iostream>
#include <queue>

using namespace std;

bool visited[100001] = {false, };

typedef struct INFO {
	int X;
	int T;
} info;

void bfs(int n, int k) {
	visited[n] = true;
	queue<info> q;
	q.push({n, 0});
	while (!q.empty()) {
		int x = q.front().X;
		int t = q.front().T;
		q.pop();
		if (x == k) { // 찾으면 출력
			cout << t << "\n";
		}
		else {
			if (x-1 >= 0 && !visited[x-1]) {
				q.push({ x - 1, t + 1 });
				visited[x - 1] = true;
			}
			if (x+1 <= 100000 && !visited[x+1]) {
				q.push({ x + 1, t + 1 });
				visited[x + 1] = true;
			}
			if (2*x <= 100000 && !visited[2*x]) {
				q.push({ 2 * x, t + 1 });
				visited[2 * x] = true;
			}
		}
	}
}

int main() {
	int N, K;
	cin >> N >> K;
	bfs(N, K);

	return 0;
}