#include <bits/stdc++.h>

using namespace std;

// 인덱스별로 (접두사 = 접미사)의 최대 길이를 구하기(전처리) -> O(M)
vector<int> preset(vector<int> P) {
    int M = P.size();
    // partial match table
    vector<int> lps(M); // 실패함수
    int f = 0;
    for (int s = 1; s < M; s++) {
        while (f >= 1 && P[f] != P[s]) {
            f = lps[f - 1]; // 검사 시작점 설정: 최대 길이의 '접두사 = 접미사' 부분 걸치기
        }
        if (P[f] == P[s]) {
            f++; // increase first idx
            lps[s] = f; // save 'index + 1'
        }
    }
    return lps;
}

// 검색 함수: O(N)
bool KMP(vector<int> T, vector<int> P) { // 텍스트, 검색어
    int M = P.size();
    int N = T.size();
    vector<int> lps = preset(P); // 전처리
    vector<int> idx; // 검색에 성공한 인덱스 저장
    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j >= 1 && T[i] != P[j]) { // 검색어 첫 글자에서 시작해 검사해야 하는 인덱스에 도달할 때까지 최대 길이의 '접두사 = 접미사' 부분 걸치기 
            j = lps[j - 1]; // 검사 시작점 설정
        }
        if (T[i] == P[j]) { // 일치하면
            if (j != M - 1) { // 검색이 끝나지 않았으면
                j++; // 다음 원소 검사
            }
            else {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<vector<int>> arr(N);
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        int a;
        cin >> a;
        int pre = a;
        for (int j = 1; j < K; j++) {
            cin >> a;
            arr[i].push_back(a - pre);
            pre = a;
        }
    }
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    */

    int L;
    cin >> L;
    vector<int> melo(L - 1);
    int b;
    cin >> b;
    int pre = b;
    for (int i = 0; i < L - 1; i++) {
        cin >> b;
        melo[i] = b - pre;
        pre = b;
    }
    vector<int> idx;
    for (int i = 0; i < N; i++) {
        if (KMP(arr[i], melo)) {
            idx.push_back(i + 1);
        }
    }
    if (idx.empty()) {
        cout << -1;
    }
    else {
        for (int i = 0; i < idx.size(); i++) {
            cout << idx[i] << " ";
        }
    }
}