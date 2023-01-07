// 셀프 넘버  // math 
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<int, bool> notSelf;
	int n = 1;
	while (n <= 10000) {
		int inte = n;
		int copy = n;
		while (copy) {
			inte += copy % 10;
			copy /= 10;
		}
		notSelf[inte] = true;
		n++;
	}
	for (int i = 1; i <= 10000; i++) {
		if (notSelf[i] == false) {
			cout << i << "\n";
		}
	}

	return 0;
}