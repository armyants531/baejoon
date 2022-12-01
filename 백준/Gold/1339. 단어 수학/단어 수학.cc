// 단어 수학 // greedy
// GCF + ACDEB = A * 10000 + C * 1010 + D * 100 + G * 100 + E * 10 + B + F
// A > C > D > G > E > B > F
#include <bits/stdc++.h>

using namespace std;

vector<int> alpha(26); // save the number of alphabet

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string val;
    cin >> val;
    for (int i = 0; i < val.size(); i++) {
      alpha[(int)(val[i] - 'A')] += pow(10, val.size() - i - 1); 
      // cout << alpha[(int)(val[i] - 'A')] << "\n";
    }
  }
  // descending order
  sort(alpha.begin(), alpha.end(), greater<int>());
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    sum += alpha[i] * (9 - i);
  }
  cout << sum << "\n";
  return 0;
}