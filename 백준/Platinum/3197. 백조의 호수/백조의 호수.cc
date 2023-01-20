// 백조의 호수  // bfs
#include <bits/stdc++.h>

using namespace std;

struct coord {
    int y;
    int x;
};

vector<vector<char>> lake;
vector<vector<bool>> visited2;
queue<coord> que_swan;
int R, C, T = 0;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

// 물을 기준으로 bfs (치즈 문제와 비슷)
queue<coord> bfs(queue<coord> que) {
    T++;
    queue<coord> que2;
    while (!que.empty()) {
        int y = que.front().y;
        int x = que.front().x;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
                if (lake[ny][nx] == 'X') {
                    lake[ny][nx] = '.'; // melted
                    que2.push({ ny, nx }); // 새로 녹은 부분을 저장 -> 이후 bfs에서 사용
                }
            }
        }
    }
    return que2;
}

// 백조 한 마리를 기준으로 bfs
bool check() {
    queue<coord> que = que_swan;
    while (!que_swan.empty()) {
        que_swan.pop();
    }
    while (!que.empty()) {
        int y = que.front().y;
        int x = que.front().x;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < R && nx >= 0 && nx < C && !visited2[ny][nx]) {
                if (lake[ny][nx] == 'X') {  // 녹아서 물이 될 예정인 부분
                    visited2[ny][nx] = true;
                    que_swan.push({ ny, nx });
                }
                else if (lake[ny][nx] == '.') {
                    visited2[ny][nx] = true;
                    que.push({ ny, nx });
                }
                else { // swan
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    lake.resize(R, vector<char>(C));
    
    visited2.resize(R, vector<bool>(C));
    queue<coord> que;
    vector<coord> swan;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            lake[i][j] = str[j];
            if (lake[i][j] == '.') {
                que.push({ i, j });
            }
            else if (lake[i][j] == 'L') { // 백조가 있는 곳은 물임
                swan.push_back({ i, j });
                que.push({ i, j });
            }
        }
    }   
    visited2[swan[0].y][swan[0].x] = true;
    que_swan.push(swan[0]);
    while (true) {
        if (check()) {
            cout << T << "\n";
            break;
        }
        else {
            que = bfs(que);
            /*
            cout << "\n"
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    cout << lake[i][j] << "";
                }
                cout << "\n";
            }
            */
        }
    }

    return 0;
}