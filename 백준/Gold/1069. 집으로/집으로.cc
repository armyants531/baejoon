#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double X, Y;
  int D, T;
	cin >> X >> Y >> D >> T;
  double time = sqrt(X * X + Y * Y); // (same as distance)
  cout << fixed;
  cout.precision(13);
  if (D <= T) {
    cout << time << "\n"; 
  }
  else {
    double close_T = (int) time / D * T;
    double time2 = close_T + (time - (int) time / D * D); // 대각선으로 점프 후 걸어서 도착
    double time3 = close_T + T + ((close_T + T) * D / T - time); // 대각선 점프 후 걸어서 돌아오기
    double time4; // 점프로만 이동
    if (close_T == 0) {
      time4 = 2 * T;
    }
    else {
      time4 = close_T + T;
    }
    
    cout << min({time, time2, time3, time4}) << "\n";
  }
}