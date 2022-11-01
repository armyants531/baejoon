#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	long arr[100000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	long p_sum[100000];
	
	p_sum[0] = arr[0];
	for (int i = 1; i < n; i++) {
		p_sum[i] = p_sum[i-1] + arr[i];
	}

	long t_sum = 0;
	for (int i = 0; i <= n - 2; i++) {
		t_sum += arr[i] * (p_sum[n-1] - p_sum[i]);
	}
	
	cout << t_sum;
}