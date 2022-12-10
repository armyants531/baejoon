#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<string> v;
    v.push_back("ChongChong");
    for (int i = 0; i < N; i++) {
        string A, B;
        cin >> A >> B;
        bool isA = false, isB = false;
        if (find(v.begin(), v.end(), A) != v.end()) {
            isA = true;
        }
        if (find(v.begin(), v.end(), B) != v.end()) {
            isB = true;
        }
        if (isA && !isB) {
            v.push_back(B);
        }
        if (!isA && isB) {
            v.push_back(A);
        }
    }
    cout << v.size() << "\n";
}