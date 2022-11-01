#include <iostream>

using namespace std;

int n;
int paper[128][128];
int b, w; // num of color

// y, x: coordinate of upper left, len: length of the quadrant
void sol(int y, int x, int len) {
  int color = paper[y][x];
  for (int i = y; i < y + len; i++) {
    for (int j = x; j < x + len; j++) {
      if ((color == 0 && paper[i][j] == 1) ||
          (color == 1 && paper[i][j] == 0)) {
        sol(y, x, len / 2);                     // upper left
        sol(y, x + len / 2, len / 2);           // upper right
        sol(y + len / 2, x + len / 2, len / 2); // lower right
        sol(y + len / 2, x, len / 2);           // lower left
        return;                                 // end point
      }
    }
  }
  if (color == 1)
    b++;
  else
    w++;
}

int main() { 
  ios_base::sync_with_stdio(false);  // c++의 독립적인 버퍼 생성
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin >> paper[i][j];
  }
  sol(0, 0, n);
  cout << w << endl;
  cout << b;

  return 0;
}