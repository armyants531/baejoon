#include <bits/stdc++.h>

using namespace std;

int solution(int N, int number) {
    vector<vector<int>> v(9); // N을 1~8번 사용
    bool can = false;
    int tmp = N;
    for (int i = 1; i <= 8; i++) {
        v[i].push_back(tmp);
        tmp *= 10;
        tmp += N;
    }
    
    if (N == number) {
        return 1;
    }
    for (int i = 2; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            for (auto A : v[j]) {
                for (auto B : v[i-j]) {
                    v[i].push_back(A+B);
                    v[i].push_back(A-B);
                    v[i].push_back(A*B);
                    if (B != 0) {
                        v[i].push_back(A/B);
                    }
                }
            }
            for (int k = 0; k < v[i].size(); k++) {
                if (v[i][k] == number) {
                    return i;
                }
            }
        }     
    }
    
    return -1;
}