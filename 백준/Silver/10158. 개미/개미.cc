#include <iostream>

using namespace std;

int main() {
  int w, h, p, q, t;
  cin >> w >> h;
  cin >> p >> q;
  cin >> t;

  int x_t, y_t, x, y;
  x_t = t % (2*w);
  y_t = t % (2*h);
  
  if (x_t <= w-p) {
    x = p + x_t;
  }
  else {
    x = abs(2*w - x_t - p); // x = abs(w - (x_t - (w - p)))
  }
  
  if (y_t <= h-q) {
    y = q + y_t;
  }
  else {
    y = abs(2*h - y_t - q);
  }

  // exception handling
  if ((p == 0 && q == h) || (p == w && q == 0)) { // when cannot move
    x = p;
    y = q;
  }

  cout << x << " " << y;
}