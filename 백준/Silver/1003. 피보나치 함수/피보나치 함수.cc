#include <iostream>

using namespace std;

int arr[41] = {0,};

int fibonacci(int n) {
    arr[0] = 0;
    arr[1] = 1;
    if (arr[n] != 0) {
        return arr[n];
    }
    else if (n <= 1) {
        return arr[n];
    }
    else {
        arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return arr[n];
    }
}

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        
        if (n == 0) {
            cout << 1 << " " << 0 << "\n";
        }
        else {
            cout << fibonacci(n - 1) << " " << fibonacci(n) << "\n";
        }
	}

	return 0;
}