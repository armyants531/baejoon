// 반짝반짝 2  // probability theory  // linearity of expected values
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
  vector<double> prob;
  double ex = 0; // 기댓값
	for (int i = 0; i < N; i++) {
    double p;
    cin >> p;
    ex += p;
    prob.push_back(p);
  }
  for (int i = 0; i < N - 1; i++) {
    ex += prob[i] * (1 - prob[i + 1]) + (1 - prob[i]) * prob[i + 1]; 
  }
  cout << fixed;
  cout.precision(12);
  cout << ex << "\n";
  
	return 0;
}