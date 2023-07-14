#include <bits/stdc++.h>
#include <random>
#define int long long

using namespace std;
typedef long long ll;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << 500 << " " << 500 * 499 << "\n";
	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 100000000);
	for (int i = 1; i < 500; i++) {
		for (int j = i + 1; j <= 500; j++) {
			cout << i << " " << j << " " << dis(gen) << "\n";
			cout << j << " " << i << " " << dis(gen) << "\n";
		}
	}

	return 0;
}