#include <iostream>
#define MAX 200000
using namespace std;

int main() {
  int A[MAX];
  int n, k, i, j, s = 0, e = 0, temp = 0;
  bool breaker = false;
  cin >> n >> k;
  for (i = 0; i < n; i++)
    cin >> A[i];
  
  for (i = 0; i < n; i++) {
    if (breaker == true) {
      s = i; // reset the starting point
      temp = 0;
      breaker = false;
    }
    if ((k | A[i]) > k) { // k가 되는 구간이 될 수 없는 경우
      breaker = true;
    } else {
      temp = temp | A[i];
      e = i;
      if (temp == k) {
        break;
      }
    }
  }

  if (temp != k)
    cout << -1;
  else {
    s++;
    e++;
    cout << s << " " << e;
  }
  return 0;
}