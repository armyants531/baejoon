#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

int m, n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<vector<int>> t(1001, vector<int>(1001)); 
vector<vector<bool>> v(1001, vector<bool>(1001)); 

struct node {
    int x, y, d;
};

struct cmp {
    bool operator() (node a, node b) { // d에 대해 오름차순
        return a.d > b.d;
    }
};

int bfs() {
    priority_queue<node, vector<node>, cmp> pq;
    if (t[0][0] == -1) {
        return -1;
    }
    else {
        v[0][0] = true;
        pq.push({0, 0, t[0][0]});
    }
    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int d = pq.top().d;
        if (x == m - 1 && y == n - 1) {
            return d;
        }
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && t[nx][ny] != -1 && v[nx][ny] == false) {
                v[nx][ny] = true;
                pq.push({nx, ny, d + t[nx][ny]});
            }
        }
    }
    return -1; // 도착칸이 -1
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }
    cout << bfs() << "\n";

    return 0;
}