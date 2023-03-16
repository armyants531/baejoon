// 멋진 부분집합  // number theory  // randomization
#include <bits/stdc++.h>
#include <random>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int half_N = ceil((double)N / 2);
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, N - 1);
    bool isExist = false;
    set<int> fact; // 소인수 저장하는 set
    // 랜덤하게 뽑은 20개 수의 소인수를 저장한다
    for (int i = 0; i < 20; i++) { 
        int num = arr[dis(gen)];
        for (int a = 2; a * a <= num; a++) {
            while (num % a == 0) {
                num /= a;
                fact.insert(a);
            }
        }
        if (num != 1) fact.insert(num);
    }
    // 주어진 수들이 소인수로 나누어 떨어지는지 판단하여 count 해준다.
    for (set<int>::iterator it = fact.begin(); it != fact.end(); it++) {
        int cnt = 0;
        vector<int> ans;
        for (int j = 0; j < N; j++) {
            if (arr[j] % *it == 0) {
                cnt++;
                ans.push_back(arr[j]);
            }
        }
        if (cnt >= half_N) { // cnt가 크기 조건을 만족하면 
            isExist = true;
            cout << "YES" << "\n";
            for (int i = 0; i < half_N; i++) { // half_N 개 만큼 출력
                cout << ans[i] << " ";
            }
            cout << "\n";
            break;
        }
        ans.clear();
    }
    if (!isExist) cout << "NO" << "\n";

    return 0;
}