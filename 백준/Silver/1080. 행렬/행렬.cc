// 행렬  // greedy
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A(50, vector<int>(50));
vector<vector<int>> B(50, vector<int>(50));

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &A[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &B[i][j]);
        }
    }
    bool canChange = true;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) {
                if (i + 3 > N || j + 3 > M) {
                    canChange = false;
                    break;
                }
                else {
                    cnt++;
                    for (int x = i; x < i + 3; x++) {
                        for (int y = j; y < j + 3; y++) {
                            if (A[x][y] == 0) {
                                A[x][y] = 1;
                            }
                            else {
                                A[x][y] = 0;
                            }
                        }
                    }
                }
            }
        }
        if (!canChange) {
            break;
        }
    }
    if (canChange) {
        cout << cnt << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}