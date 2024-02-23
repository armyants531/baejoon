#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool v[101][101];
int t[101][101];

struct node {
    int x, y, cnt;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 100000;
    int N = rectangle.size();
    vector<vector<int>> rect(N, vector<int>(4));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            rect[i][j] = 2 * rectangle[i][j]; // 겹치는 부분 없에기 위해 x 2 한 좌표 생각
        }
    }
    // 직사각형 내부 모두 칠하기
    for (int i = 0; i < N; i++) {
        for (int x = rect[i][0]; x <= rect[i][2]; x++) {
            for (int y = rect[i][1]; y <= rect[i][3]; y++) {
                t[x][y] = 1;
            }
        }
    }
    // 직사각형 테두리 제외 모두 지우기
    for (int i = 0; i < N; i++) {
        for (int x = rect[i][0] + 1; x < rect[i][2]; x++) {
            for (int y = rect[i][1] + 1; y < rect[i][3]; y++) {
                t[x][y] = 0;
            }
        }
    }
    // 테두리 따라 bfs
    queue<node> que;
    que.push({characterX * 2, characterY * 2, 0});
    v[characterX * 2][characterY * 2] = true;
    while (!que.empty()) {
        int x = que.front().x;
        int y = que.front().y;
        int cnt = que.front().cnt;
        que.pop();
        if (itemX * 2 == x && itemY * 2 == y) {
            answer = min(answer, cnt);
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 100 && nx >= 2 && ny <= 100 && ny >= 2 && !v[nx][ny] && t[nx][ny] == 1) {
                que.push({nx, ny, cnt + 1});
                v[nx][ny] = true;
            } 
        }
    }
    answer /= 2;
    return answer;
}