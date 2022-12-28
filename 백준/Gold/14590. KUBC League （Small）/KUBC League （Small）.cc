// KUBC League (Small)  // DP  // bitmasking  // TSP(Travelling Salesman Problem)
#include <bits/stdc++.h>

using namespace std;
int cache[20][1 << 20];  // save max len
vector<vector<int>> arr(20, vector<int>(20));

int memo(int current, int status, int N) {
    // 방문 처리
    status |= (1 << current);
    int& ans = cache[current][status];
    if (status == (1 << N) - 1) { // if all visited
        //cout << status << "\n";
        return ans = 1;
    }
    if (ans != -1) { // already calc
        return ans;
    }
    ans = 1;
    for (int next = 0; next < N; next++) {
        if (arr[current][next] != 0 && (status & (1 << next)) == 0) { // if can visit && not visited
            ans = max(ans, memo(next, status, N) + 1);
        }
    }
    //cout << status << "\n";
    return ans;
}

void tracking(int current, int status, int N) {
    for (int next = 0; next < N; next++) {
        if (arr[current][next] != 0 && (status & (1 << next)) == 0) { // if can visit && not visited
            if (cache[current][status] == cache[next][status | (1 << next)] + 1) {
                cout << next + 1 << " ";
                tracking(next, status | (1 << next), N);
                break;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    cout << memo(0, 0, N) << "\n";
    cout << 1 << " ";
    tracking(0, 1, N); // status: 1에서 시작
    cout << "\n";

    return 0;
}