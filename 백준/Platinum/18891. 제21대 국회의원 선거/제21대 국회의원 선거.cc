// 제21대 국회의원 선거  // implementaion
#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, double> A, pair<int, double> B) {
	if (A.second == B.second) { // 소수점 이하의 수가 같다면 기호가 더 작은 정당에 먼저 배분
		A.first < B.first;
	}
	return A.second > B.second; // 내림차순
}
bool compare2(pair<string, int> A, pair<string, int> B) {
	if (A.second == B.second) {
		return A.first < B.first;
	}
	return A.second > B.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int P, V;
	cin >> P >> V;
	vector<int> r(P); // 지역구 의석
	vector<double> rate(P); // 득표율
	vector<double> p(P); // 비례 득표율
	vector<int> p_cnt(P); // 비례대표국회의원선거 득표수
	vector<pair<string, int>> party(P);
	int r_sum = 0; // 의석 할당 정당의 지역구 당선인 수 총합
	int rate_sum = 0; // 총 득표수
	int p_sum = 0; // 의석할당 정당들의 비례대표국회의원선거 총 득표수
	for (int i = 0; i < P; i++) {
		cin >> party[i].first >> r[i] >> p_cnt[i];
		rate_sum += p_cnt[i];
	}
	// 해당 정당의 비례대표국회의원선거 득표비율(p) 구하기
	vector<bool> can(P);
	for (int i = 0; i < P; i++) {
		rate[i] = (double)p_cnt[i] / rate_sum;
		// 비례대표 의석을 배분받는 정당(의석할당정당) 표시
		if (rate[i] >= 0.03 || r[i] >= 5) {
			can[i] = true;
		}
	} 
	for (int i = 0; i < P; i++) {
		if (can[i]) { // 의석할당정당이면
			r_sum += r[i];
			p_sum += p_cnt[i];
		}
	}
	/*
	// test code
	cout << "0단계" << "\n";
	for (int i = 0; i < P; i++) {
		cout << r[i] << " " << rate[i] << "\n";
	}
	cout << "\n";
	*/
	// 1단계
	// 비례 득표율 계산
	for (int i = 0; i < P; i++) {
		if (!can[i]) continue;
		p[i] = (double)p_cnt[i] / p_sum;
	}
	int N = 300;
	int R = 253 - r_sum;
	int N_R = N - R;
	vector<int> s(P); // 연동배분 의석 수
	int s_sum = 0; // 연동배분 의석 수 합계
	for (int i = 0; i < P; i++) {
		if (!can[i]) continue;
		double cnt = (N_R * p[i] - r[i]) / 2;
		if (cnt < 1) {
			s[i] = 0;
		}
		else {
			s[i] = round(cnt);
			s_sum += s[i];
		}
	}
	/*
	// test code
	cout << "1단계" << "\n";
	for (int i = 0; i < P; i++) {
		cout << r[i] << " " << p[i] << " " << s[i] << "\n";
	}
	cout << "\n";
	*/
	// 2단계
	if (s_sum < 30) { // 2-1
		int rem = 30 - s_sum;
		vector<pair<int, double>> decimal(P);
		for (int i = 0; i < P; i++) {
			decimal[i].first = i;
		}
		for (int i = 0; i < P; i++) {
			if (!can[i]) continue;
			double num = (30 - s_sum) * p[i];
			int integer = floor(num);
			decimal[i].second = num - integer;
			s[i] += integer;
			rem -= integer;
		}
		sort(decimal.begin(), decimal.end(), compare);
		int i = 0;
		while (rem) {
			s[decimal[i].first]++;
			rem--;
			i++;
		}
	}
	else if (s_sum > 30) { // 2-2
		vector<int> s_copy(P);
		for (int i = 0; i < P; i++) {
			s_copy[i] = s[i];
		}
		int rem = 30;
		vector<pair<int, double>> decimal(P);
		for (int i = 0; i < P; i++) {
			decimal[i].first = i;
		}
		for (int i = 0; i < P; i++) {
			if (!can[i]) continue;
			double num = (double)30 * s_copy[i] / s_sum;
			int integer = floor(num);
			decimal[i].second = num - integer;
			s[i] = integer;
			rem -= integer;
		}
		sort(decimal.begin(), decimal.end(), compare);
		int i = 0;
		while (rem) {
			s[decimal[i].first]++;
			rem--;
			i++;
		}
	}
	/*
	// test code
	cout << "2단계" << "\n";
	for (int i = 0; i < P; i++) {
		cout << s[i] << "\n";
	}
	cout << "\n";
	*/
	// 3단계
	int rem = 17;
	vector<int> t(P);
	vector<pair<int, double>> decimal(P);
	for (int i = 0; i < P; i++) {
		decimal[i].first = i;
	}
	for (int i = 0; i < P; i++) {
		if (!can[i]) continue;
		double num = 17 * p[i];
		int integer = floor(num);
		decimal[i].second = num - integer;
		t[i] = integer;
		rem -= integer;
	}
	sort(decimal.begin(), decimal.end(), compare);
	int i = 0;
	while (rem) {
		t[decimal[i].first]++;
		rem--;
		i++;
	}
	/*
	// test code
	cout << "3단계" << "\n";
	for (int i = 0; i < P; i++) {
		cout << p[i] << " " << t[i] << "\n";
	}
	cout << "\n";
	*/
	// 출력
	for (int i = 0; i < P; i++) {
		party[i].second = s[i] + t[i] + r[i]; 
	}
	sort(party.begin(), party.end(), compare2);
	for (int i = 0; i < P; i++) {
		cout << party[i].first << " " << party[i].second << "\n";
	}
	
	return 0;
}