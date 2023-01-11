// 나이트의 이동  // bfs
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool visited[301][301];
int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

struct coord {
  int y;
  int x;
  int cnt;
};

int bfs(int l, int y1, int x1, int y2, int x2) {
  if (y1 == y2 && x1 == x2) {
    return 0;
  }
  visited[y1][y2] = true;
  queue<coord> que;
  que.push({y1, x1, 0});
  while (!que.empty()) {
    coord node = que.front();
    que.pop();
    int ncnt = node.cnt + 1;
    for (int i = 0; i < 8; i++) {
      int ny = node.y + dy[i];
      int nx = node.x + dx[i];
      if (ny >= 0 && ny <= l - 1 && nx >= 0 && nx <= l - 1 && !visited[ny][nx]) {
        if (ny == y2 && nx == x2) {
          return ncnt;
        }
        visited[ny][nx] = true;
        que.push({ny, nx, ncnt});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int l;
    cin >> l;
    int y1, x1, y2, x2;
    cin >> y1 >> x1;
    cin >> y2 >> x2;
    cout << bfs(l, y1, x1, y2, x2) << "\n";
    memset(visited, 0, sizeof(visited));
  }
  
  return 0;
}