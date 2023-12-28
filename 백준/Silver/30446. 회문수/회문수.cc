// 회문수
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string N;
	cin >> N;
	int len = N.size();
	ll cnt = 0;
	// len자리 미만 회문수 개수 
	for (int i = 1; i < len; i++) {
		cnt += 9 * pow(10, (i - 1) / 2); 
	}
	if (N.size() > 1) {
		// len 자리수 회문수 개수 
		string pal = N.substr(0, len / 2);
		reverse(pal.begin(), pal.end());
		string N_end = N.substr((len + 1) / 2, (len + 1) / 2);
		ll last;
		//cout << pal << " " << N_end << "\n";
		if (stoi(pal) <= stoi(N_end)) {
			last = stoi(N.substr(0, (len + 1) / 2));
		}
		else {
			last = stoi(N.substr(0, (len + 1) / 2)) - 1;
		}
		cnt += last - pow(10, (len + 1) / 2 - 1) + 1;
	}
	else { // 한 자리 수 
		cnt += stoi(N);
	}
	cout << cnt << "\n";
	return 0;
}