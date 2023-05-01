// 증가 배열 만들기
#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int table[1000][1000] = {0, };
bool isExist = false;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M >> K;
  if (N + M - 1 <= K) { 
    cout << "YES" << "\n";
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << i + j + 1 << " ";
      }
      cout << "\n";
    }
  }
  else {
    cout << "NO" << "\n";
  }

  return 0;
}