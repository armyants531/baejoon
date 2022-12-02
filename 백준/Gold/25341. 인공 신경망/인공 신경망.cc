// 인공 신경망  // 수학  // 구현  // 사칙연산
// 빠른 사칙 연산을 위해 "출력값 = 상수 + 입력값 * multiplicand"에서 multiplicand와 상수값을 계산해둔다  
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> input(Q);
    vector<vector<ll>> hidden_layer_P(M);
    vector<vector<ll>> hidden_layer_W(M);
    vector<ll> hidden_layer_B;
    //vector<ll> output_layer_W;
    ll output_layer_B;
    vector<ll> multiplicand(2000); // 입력값에 곱할 수들 저장
    // 은닉층 정보 저장
    for (int i = 0; i < M; i++) {
        ll C;
        cin >> C;
        ll P;
        for (int j = 0; j < C; j++) {
            cin >> P;
            hidden_layer_P[i].push_back(P);
        }
        ll W;
        for (int j = 0; j < C; j++) {
            cin >> W;
            hidden_layer_W[i].push_back(W);
        }
        ll B;
        cin >> B;
        hidden_layer_B.push_back(B);
    }
    // 출력층 정보 저장
    ll W;
    for (int i = 0; i < M; i++) {
        cin >> W;
        for (int j = 0; j < hidden_layer_P[i].size(); j++)
            // 입력값에 해당하는 multiplicand를 hidden_layer_W[i][j] * W 만큼 증가시킴      
            multiplicand[hidden_layer_P[i][j] - 1] += hidden_layer_W[i][j] * W;
        hidden_layer_B[i] *= W;
    }
    cin >> output_layer_B;
    // 입력층 정보 저장
    for (int i = 0; i < Q; i++) {
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            input[i].push_back(x);
        }
    }
    // 상수 + 입력값 * multiplicand(빠른 사칙 연산)
    ll constant = output_layer_B;
    for (int i = 0; i < M; i++) {
        constant += hidden_layer_B[i];
    }
    for (int i = 0; i < Q; i++) {
        ll sum = constant;
        for (int j = 0; j < N; j++) {
            sum += input[i][j] * multiplicand[j];
        }
        cout << sum << "\n";
    }
   
    return 0;
}