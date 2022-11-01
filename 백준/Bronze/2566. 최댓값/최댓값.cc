#include <iostream>
using namespace std;

int matrix[9][9];

int main() {
  int max = 0;
  int row = 0, col = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> matrix[i][j];
      if (matrix[i][j] >= max) {
        max = matrix[i][j];
        row = i + 1;
        col = j + 1;
      }
    }
  }
  cout << max << "\n";
  cout << row << " " << col << "\n";
  return 0;
}