// 골드바흐 파티션
#include <bits/stdc++.h>

using namespace std;

vector<int> arr(1000001);
vector<int> primes;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  for (int i = 2; i < 1000001; i++) {
    arr[i] = i;
  }
  // 2부터 시작하여 소수의 배수(2배수, 3배수,...)에 해당하는 수를 모두 지움(이미 지워진 경우 제외)
  for (int i = 2; i < 1000001; i++) {
    if (arr[i] == 0) continue;
    for (int j = i * 2; j < 1000001; j += i) arr[j] = 0;
  }
  
  for (int i = 2; i < 1000001; i++) {
    if (arr[i]) {
      primes.push_back(i);
    }
  }
	int T;
  cin >> T;
  int N;
  for (int t = 0; t < T; t++) {
    cin >> N;
    int cnt = 0;
    int half_N = N / 2;
    for (int i = 0; i < primes.size(); i++) {
      if (primes[i] > N / 2) {
        break;
      }
      if (arr[N - primes[i]] != 0) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}