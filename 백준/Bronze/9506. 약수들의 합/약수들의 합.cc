#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N ;
    cin >> N;
    while (N != -1) {
    	vector<int> arr;
    	for (int i = 1; i < N; i++) {
    		if (N % i == 0) {
    			arr.push_back(i);
			}
		}
		int sum = 0;
		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i];
		}
		if (sum == N) {
			cout << N << " = ";
			for (int i = 0; i < arr.size() - 1; i++) {
				cout << arr[i] << " + ";
			}
			cout << arr[arr.size() - 1] << "\n";
		}
		else {
			cout << N << " is NOT perfect." << "\n";
		}
    	cin >> N;
	}
}