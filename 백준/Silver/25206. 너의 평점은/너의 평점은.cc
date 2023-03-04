#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string name; 
	double credit;
	string grade;
	double tot = 0;
	double tot_credit = 0;
	for (int i = 1; i <= 20; i++) {
		cin >> name >> credit >> grade;
		if (grade == "A+") {
			tot += credit * 4.5;
			tot_credit += credit;
		}
		else if (grade == "A0") {
			tot += credit * 4.0;
			tot_credit += credit;
		}
		else if (grade == "B+") {
			tot += credit * 3.5;
			tot_credit += credit;
		}
		else if (grade == "B0") {
			tot += credit * 3.0;
			tot_credit += credit;
		}
		else if (grade == "C+") {
			tot += credit * 2.5;
			tot_credit += credit;
		}
		else if (grade == "C0") {
			tot += credit * 2.0;
			tot_credit += credit;
		}
		else if (grade == "D+") {
			tot += credit * 1.5;
			tot_credit += credit;
		}
		else if (grade == "D0") {
			tot += credit * 1.0;
			tot_credit += credit;
		}
		else if (grade == "F") {
			tot_credit += credit;
		}
	}
	cout << fixed;
	cout.precision(6);
	cout << tot / tot_credit << "\n";
	
	return 0;
}