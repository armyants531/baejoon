// 다각형의 면적  // geometry
#include <bits/stdc++.h>

using namespace std;

struct point {
  double x;
  double y;
};

double determinant(point A, point B) {
  return A.x * B.y - A.y * B.x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  vector<point> points;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    point p;
    cin >> p.x >> p.y;
    points.push_back(p);
  }
  double A = 0;
  for (int i = 0; i < N - 1; i++) {
    A += determinant(points[i], points[i+1]);
  }
  A += determinant(points[N - 1], points[0]);
  cout << fixed;
  cout.precision(1);
  double ans = A / 2;
  if (ans < 0) {
    cout << -ans << "\n";
  }
  else {
    cout << ans << "\n";
  }
  
	return 0;
}