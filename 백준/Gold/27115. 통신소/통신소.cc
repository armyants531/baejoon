// 통신소 // bfs
// 세기 p의 전파는 상하좌우로 퍼지면서 세기가 p-1이 된다.
// 퍼져나간 칸에 이미 더 강한 전파가 있으면 세기가 더 약한 전파는 퍼지지 않아도 됨
// 전파 세기에 대해 내림차순으로 queue에 넣으면서 BFS 돌리면 동일한 격자점에 여러 번 접근하는 것 방지 가능 
// O(NM + K*log K)
#include <bits/stdc++.h>

using namespace std;

struct cs {
    int p;
    int y;
    int x;
};

int board[3001][3001];
int N, M, K;
deque<cs> deq;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int cnt = 0;

void bfs() {
    queue<cs> que;
    cs first = deq.front();
    que.push(first);
    cnt++;
    board[first.y][first.x] = first.p;
    deq.pop_front();
    while (!que.empty()) {
        cs A = que.front();
        que.pop();
        if (A.p <= 0) {     
        }
        else if ((!deq.empty() && deq.front().p <= A.p - 1) || deq.empty()) { // 퍼저나가는 전파의 크기(A.p - 1)가 deq.front().p 보다 더 크거나 같음
            for (int i = 0; i < 4; i++) {
                int ny = A.y + dy[i];
                int nx = A.x + dx[i];
                int np = A.p - 1;
                if (ny <= N && ny >= 1 && nx <= M && nx >= 1 && board[ny][nx] == -1) {
                    que.push({ np, ny, nx });
                    cnt++;
                    board[ny][nx] = np;
                }
            }
        }
        else { // !deq.empty() && deq.front().p > A.p - 1
            // deq.front() <= A.p - 1가 될 때까지
            while (!deq.empty() && deq.front().p > A.p - 1) {
                que.push(deq.front());
                cnt++;
                board[deq.front().y][deq.front().x] = deq.front().p;
                deq.pop_front();
            } 
            for (int i = 0; i < 4; i++) {
                int ny = A.y + dy[i];
                int nx = A.x + dx[i];
                int np = A.p - 1; // 1 이상임
                if (ny <= N && ny >= 1 && nx <= M && nx >= 1 && board[ny][nx] == -1) {
                    que.push({ np, ny, nx });
                    cnt++;
                    board[ny][nx] = np;
                }
            }
        }
        // que가 비었으면 deq로 채워넣기
        if (que.empty() && !deq.empty()) {
            que.push(deq.front());
            cnt++;
            board[deq.front().y][deq.front().x] = deq.front().p;
            deq.pop_front();
        }
    }
}

bool compare(cs A, cs B) {
    if (A.p > B.p) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    memset(board, -1, sizeof(board));
    for (int i = 0; i < K; i++) {
        int y, x, p;
        cin >> y >> x >> p;
        deq.push_back({ p, y, x });
    }
    sort(deq.begin(), deq.end(), compare);
    
    bfs();
    /*
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout.width(2);
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    */

    //cout << cnt << "\n";
    int count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (board[i][j] != -1) {
                count++;
            }
        }
    }
    cout << count << "\n";

    return 0;
}