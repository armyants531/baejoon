// NMK  // greedy
// https://hongjw1938.tistory.com/191 참고
// M + K - 1 <= N <= M x K
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K;
    cin >> N >> M >> K;
    queue<int> que; // 1~N 까지의 수 저장
    for (int i = 1; i <= N; i++) {
        que.push(i);
    }
    if (M + K - 1 <= N && N <= M * K) {
        vector<stack<int>> st(M); // M개의 감소 수열 저장
        // 길이가 K인 감소 수열 만들기(1~K)
        for (int i = 0; i < K; i++) {
            st[0].push(que.front());
            que.pop();
        }
        if (M != 1) {
            // N - K 개를 M - 1개의 감소 수열로 만들기
            int q = (N - K) / (M - 1);
            int r = (N - K) % (M - 1);
            // q + 1 길이의 감소 수열 r개 생성
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= q + 1; j++) {
                    st[i].push(que.front());
                    que.pop();
                }
            }
            // q 길이의 감소 수열 M - 1 - r개 생성
            for (int i = r + 1; i <= M - 1; i++) {
                for (int j = 1; j <= q; j++) {
                    st[i].push(que.front());
                    que.pop();
                }
            }
        }
        // 출력
        for (int i = 0; i < M; i++) {
            while (!st[i].empty()) {
                cout << st[i].top() << " ";
                st[i].pop();
            }
        }
        cout << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}