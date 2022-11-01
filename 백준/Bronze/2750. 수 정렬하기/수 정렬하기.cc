#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  // selection sort
  for (int i = 0; i < n; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[min] > arr[j]) {
        min = j;
      }
    }
    // swap
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
  delete[] arr;
}