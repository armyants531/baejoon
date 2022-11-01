#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int x1, x2, x3, x4, y1, y2, y3, y4;
	int len, max = 0;
	int arr[12];

	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	
	arr[0] = abs(x1 - x2);
	arr[1] = abs(x1 - x3);
	arr[2] = abs(x1 - x4);
	arr[3] = abs(x2 - x3);
	arr[4] = abs(x2 - x4);
	arr[5] = abs(x3 - x4);
	arr[6] = abs(y1 - y2);
	arr[7] = abs(y1 - y3);
	arr[8] = abs(y1 - y4);
	arr[9] = abs(y2 - y3);
	arr[10] = abs(y2 - y4);
	arr[11] = abs(y3 - y4);

	len = *max_element(arr, arr+12);

	cout << len * len << "\n";
}