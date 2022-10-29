#include <iostream>

using namespace std;

int main() {

  long long n, remainder;

  cin >> n;

  remainder = n % 7;

  if (remainder == 2 || remainder == 0) {

    cout << "CY" << "\n";

  }

  else {

    cout << "SK" << "\n";

  }

  return 0;

}