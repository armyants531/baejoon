// 두 원  // geometry
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  double x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  double l = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  cout << fixed;
  cout.precision(3);
  if (l >= r1 + r2) { // not overlab
    cout << 0.000 << "\n";
  }
  else if (r2 >= r1 + l) {
    cout << M_PI * r1 * r1 << "\n"; 
  }
  else if (r1 >= r2 + l) {
    cout << M_PI * r2 * r2 << "\n";
  }
  else {
    double theta1 = acos((r1 * r1 + l * l - r2 * r2) / (2 * r1 * l));
    double theta2 = acos((r2 * r2 + l * l - r1 * r1) / (2 * r2 * l));
    double A = l * r1 * sin(theta1);
    double B = r1 * r1 * theta1 + r2 * r2 * theta2;
    double ans = B - A;
    cout << ans << "\n";
  }
  
	return 0;
}