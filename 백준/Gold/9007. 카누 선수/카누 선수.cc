// 카누 선수 // Meet in the middle // binary search
#include <bits/stdc++.h>

using namespace std;

vector<int> A, B, C, D;
vector<int> AB, CD;

int binarySearch(int low, int high, int K, int size) {
	int mid = (low + high) / 2;
	while (low <= high) {
		mid = (low + high) / 2;
		if (CD[mid] == K) {
			return K;
		}
		else if (CD[mid] > K) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	int approxi;
	if (mid >= 1 && K - CD[mid - 1] <= abs(K - CD[mid])) {
		approxi = CD[mid - 1];
	}
	else {
		approxi = CD[mid];
	}

	if (mid + 1 < size && abs(K - approxi) > abs(K - CD[mid + 1])) {
		approxi = CD[mid + 1];
	}
	return approxi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int K, N, weight;
		cin >> K >> N;
		for (int j = 0; j < N; j++) {
			cin >> weight;
			A.push_back(weight);
		}
		for (int j = 0; j < N; j++) {
			cin >> weight;
			B.push_back(weight);
		}
		for (int j = 0; j < N; j++) {
			cin >> weight;
			C.push_back(weight);
		}
		for (int j = 0; j < N; j++) {
			cin >> weight;
			D.push_back(weight);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				AB.push_back(A[i] + B[j]);
				CD.push_back(C[i] + D[j]);
			}
		}
		sort(CD.begin(), CD.end()); // CD를 오름차순 정렬
		int low = 0;
		int high = N * N - 1;
		int sol = 80000000;
		for (int i = 0; i < N * N; i++) {
			int approxi = binarySearch(low, high, K - AB[i], N * N);
			if (approxi == K - AB[i]) {
				sol = K;
				break;
			}
			if (abs(K - (approxi + AB[i])) < abs(K - sol)) {
				sol = approxi + AB[i];
			}	
			else if ((abs(K - (approxi + AB[i])) == abs(K - sol)) && sol > approxi + AB[i]) {
				sol = approxi + AB[i];
			}
		}
		cout << sol << "\n";
		A.clear(); B.clear(); C.clear(); D.clear();
		AB.clear(); CD.clear();
	}
	return 0;
}