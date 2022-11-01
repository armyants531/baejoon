#include <iostream>
#include <queue>
#include <algorithm> // sort
#include <vector>

using namespace std;

int cnt = 0;
int n; // input
string map[26];
bool visited[26][26] = { 0, }; // init with false
vector<int> result;
queue<pair<int, int>> que;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int y, int x) {
	que.push({ y, x });
	visited[y][x] = true;

	while (!que.empty()) {
		int y = que.front().first;
		int x = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n && map[ny][nx] == '1' && visited[ny][nx] == 0) {
				que.push({ ny, nx });
				cnt++;
				visited[ny][nx] = true;
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && visited[i][j] == 0) {
				cnt = 1;
				bfs(i, j);
				result.push_back(cnt);
			}
		}
	}

	sort(result.begin(), result.end());
	int num = result.size();
	cout << num << "\n";
	for (int i = 0; i < num; i++) {
		cout << result[i] << "\n";
	}
	return 0;
}