// 시험  // binary search
// For some D, sum(Pi) / sum(Qi) >= D
// sum(-Qi * D + Pi) >= 0
// -Qi * D + Pi 값이 가장 큰 Qi, Pi 쌍 K개를 더해 0 이상인지 확인 
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct point {
  int P;
  int Q;
};

vector<point> arr;
int N, K;

// -Qi * D + Pi 값이 가장 큰 Qi, Pi 쌍 K개를 더해 리턴 
double cal(double D) {
  double sum = 0;
  vector<double> val;
  for (int i = 0; i < N; i++) {
  	val.push_back(- arr[i].Q * D + arr[i].P);
  }
  sort(val.begin(), val.end(), greater<double>());
  for (int i = 0; i < K; i++) {
  	sum += val[i]; 
  }
  return sum;
}

double binary_search() {
  double low = 0;
  double high = 1;
  double mid;
  int i = 0;
  double max_D = 0;
  while (i < 30) { // 적당히 반복 
    mid = (low + high) / 2;
    i++;
    if (cal(mid) >= 0) {
      max_D = max(max_D, mid);
      low = mid;
    }
    else {
      high = mid;
    }
  }
  return max_D;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> K;
  int P, Q;
  
  for (int i = 0; i < N; i++) {
    cin >> P >> Q;
    arr.push_back({P, Q});
  }
  
  cout << fixed;
  cout.precision(12);
  cout << binary_search() << "\n";
  
  return 0;
}