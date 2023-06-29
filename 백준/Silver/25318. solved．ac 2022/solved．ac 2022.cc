#include <bits/stdc++.h>
#include <ctime>
#include <string>

using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	string s1, s2;
	vector<int> year(N);
	vector<int> mouth(N);
	vector<int> day(N);
	vector<int> hour(N);
	vector<int> minute(N);
	vector<int> sec(N);
	vector<int> l(N);
	for (int i = 0; i < N; i++) {
		cin >> s1 >> s2 >> l[i];
		year[i] = stoi(s1.substr(0, 4));
		mouth[i] = stoi(s1.substr(5, 2));
		day[i] = stoi(s1.substr(8, 2));
		hour[i] = stoi(s2.substr(0, 2));
		minute[i] = stoi(s2.substr(3, 2));
		sec[i] = stoi(s2.substr(6, 2));
		//cout << year[i] << " " << mouth[i] << " " << day[i] << " " << hour[i] << " " << minute[i] << " " << sec[i] << "\n";
	}
	vector<double> diff(N);
	for (int i = 0; i < N; i++) {
		time_t start, end;
		struct tm st, ed;
		int tm_day, tm_hour, tm_min, tm_sec;
		ed.tm_year = year[N - 1] - 1900;
		ed.tm_mon = mouth[N - 1] - 1;
		ed.tm_mday = day[N - 1];
		ed.tm_hour = hour[N - 1];
		ed.tm_min = minute[N - 1];
		ed.tm_sec = sec[N - 1];
		ed.tm_isdst = 0; // 썸머 타임 사용 안함

		st.tm_year = year[i] - 1900;
		st.tm_mon = mouth[i] - 1;
		st.tm_mday = day[i];
		st.tm_hour = hour[i];
		st.tm_min = minute[i];
		st.tm_sec = sec[i];
		st.tm_isdst = 0; // 썸머 타임 사용 안함
		start = mktime(&st);
		end = mktime(&ed);
		diff[i] = difftime(end, start) / 31536000;
	}

	double p_sum = 0;
	vector<double> p(N);
	for (int i = 0; i < N; i++) {
		p[i] = max(pow(0.9, N - i - 1), pow(0.5, diff[i]));
		p_sum += p[i];
	}
	double pl_sum = 0;
	for (int i = 0; i < N; i++) {
		pl_sum += p[i] * l[i];
	}
	int X = round(pl_sum / p_sum);
	if (N == 0) {
		cout << 0 << "\n";
	}
	else {
		cout << X << "\n";
	}

	return 0;
}