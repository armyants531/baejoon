#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;
typedef long long ll;
vector<pair<int, int>> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double h = 0;
	double s = 0;
	char a[10000];
	cin.getline(a, 10000); // 한 줄 읽기 
	//cout << strlen(a) << "\n";
	for (int i = 0; i < strlen(a); i++) {
		//cout << a[i] << " ";
		if (a[i] == 'A') {
			h++;
			s++;
		}
		else if (a[i] == 'H' || a[i] == 'P' || a[i] == 'Y') {
			h++;
		}
		else if (a[i] == 'S' || a[i] == 'D') {
			s++;
		}
	}
	cout << fixed;
	cout.precision(2); // 소수점 2자리까지 
	double H;
	if (h == 0 && s == 0) {
		H = 50.00;
	} 
	else {
		H = round(h / (h + s) * 10000); // 소수점 셋째 자리에서 반올림
		H /= 100;
	}
	cout << H;
	 
	return 0;
}