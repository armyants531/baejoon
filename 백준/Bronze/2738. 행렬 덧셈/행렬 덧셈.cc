#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> arr(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		} 
	}
	int A;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A;
			arr[i][j] += A;
		} 
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		} 
		cout << "\n";
	}
	
	return 0;
}