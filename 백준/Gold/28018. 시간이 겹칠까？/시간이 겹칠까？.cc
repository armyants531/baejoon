#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, S, E;
    cin >> N;
    vector<int> arr(1000001);
    vector<int> pre_sum(1000001);
    for (int i = 1; i <= N; i++) {
		cin >> S >> E;
		arr[S - 1] += 1;
		arr[E] -= 1;
	}
	int sum = 0;
	for (int i = 0; i < 1000001; i++) {
		sum += arr[i];
		pre_sum[i] = sum;
	}
	int Q;
	cin >> Q; 
	int t;
	for (int i = 0; i < Q; i++) {
		cin >> t;
		cout << pre_sum[t - 1] << "\n";
	}
}