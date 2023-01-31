// Ball  // math
// https://blog.myungwoo.kr/83 참고
// W = 0, R = 1, G = 2
// 1번 지난 이후 색 = (A[i] + A[i+1]) % 3
// 3^k번 지난 이후 색 = (A[i] + A[i+3^k]) % 3 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> A(20001);
vector<int> B(20001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string S;
        ll N;
        cin >> S >> N;
        int len = S.size();
        for (int i = 0; i < len; i++) {
            if (S[i] == 'W') {
                A[i] = 0;
            }
            else if (S[i] == 'R') {
                A[i] = 1;
            }
            else { // G
                A[i] = 2;
            }
        }
        ll v = 1;
        ll N_3 = N / 3;
        while (N_3 >= v) {
            v *= 3;
        }
        for (; v; v /= 3) while (N >= v) {
            for (int i = 0; i < len; i++) {
                B[i] = (A[i] + A[(i + v) % len]) % 3;
            }
            for (int i = 0; i < len; i++) {
                A[i] = B[i];
            }
            N -= v;
        }
        
        /*
        ll power_3 = 1;
        ll N_3 = N / 3;
        // N이하의 N과 가장 가까운 3의 거듭제곱 값 구하기
        while (N_3 >= power_3) {
            power_3 *= 3;
        }
        for (ll val = power_3; N > 0;) {
            int remainder = val % len;
            for (int i = 0; i < len; i++) {
                B[i] = (A[i] + A[(i + remainder) % len]) % 3;
            }
            for (int i = 0; i < len; i++) {
                A[i] = B[i];
            }
            N -= val; // N에서 3의 거듭제곱 값을 계속 빼 줌 
            if (N < val) { // N이 val 보다 작으면 
                val /= 3;
            }
        }
        */
        vector<int> cnt(3); // W, R, G 갯수 세기
        for (int i = 0; i < len; i++) cnt[A[i]]++;
        cout << "Case #" << t << ": ";
        for (int i = 0; i < 3; i++) {
            cout << cnt[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}