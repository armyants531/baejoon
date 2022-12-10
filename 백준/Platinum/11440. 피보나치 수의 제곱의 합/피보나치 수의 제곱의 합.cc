//피보나치 수의 제곱의 합  // 분할 정복을 이용한 거듭제곱
// F(n)F(n+1)
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// 행렬곱 함수
vector<vector<ll>> matrix_mult(vector<vector<ll>> matrix1,
                               vector<vector<ll>> matrix2, ll c) {
  int N = matrix1.size();
  int M = matrix1[0].size();
  int K = matrix2[0].size();
  vector<vector<ll>> matrix3(N, vector<ll>(K, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      for (int k = 0; k < M; k++) {
        matrix3[i][j] += matrix1[i][k] * matrix2[k][j] % c;
      }
      matrix3[i][j] %= c;
    }
  }
  return matrix3;
}

// a의 b거듭제곱을 c로 나눔
vector<vector<ll>> power(vector<vector<ll>> matrix, ll b, ll c) {
  if (b == 1) {
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        matrix[i][j] %= c;
      }
    }
    return matrix;
  }
  vector<vector<ll>> pow = power(matrix, b / 2, c);
  if (b % 2 == 0) {
    return matrix_mult(pow, pow, c);
  } else {
    return matrix_mult(matrix_mult(pow, pow, c), matrix, c);
  }
}

ll fibonacci(ll n, ll c) { 
  vector<vector<ll>> A = {{1, 1}, {1, 0}};
  if (n == 0) {
    return 0;
  }
  else if (n == 1) {
    return 1;
  }
  else {
    return power(A, n - 1, c)[0][0];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll n;
  cin >> n;
  cout << (fibonacci(n, 1000000007) * fibonacci(n + 1, 1000000007)) % 1000000007 << "\n";
  
  return 0;
}