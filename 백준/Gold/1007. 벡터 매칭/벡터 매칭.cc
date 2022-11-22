// 벡터 매칭
// 벡터의 절반(N/2개)을 더하고 절반을 빼면 벡터의 합이 되고 이 중 길이가 최소인 것을 찾는다.
#include <bits/stdc++.h>

using namespace std;

struct point {
	double x;
	double y;
};

vector<point> points; // 점들의 집합
vector<point> vector_sum_arr; // vector_sum들의 집합

// nCr의 경우의 수 만큼 r개 벡터의 합을 저장 
void combination(int n, int r, int depth, int next, point vector_sum) {
	if (depth == r) {
		vector_sum_arr.push_back(vector_sum);
		return;
	}
	for (int i = next; i < n; i++) {
		point vector_sum_copy = vector_sum; // deep copy 
		vector_sum_copy.x += points[i].x;
		vector_sum_copy.y += points[i].y;
		combination(n, r, depth + 1, i + 1, vector_sum_copy);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		point vector_sum = { 0, 0 };
		point all_vector_sum = { 0, 0 };
		point vector_result;
		for (int j = 0; j < N; j++) {
			point p;
			cin >> p.x >> p.y;
			points.push_back(p);
			all_vector_sum.x += p.x;
			all_vector_sum.y += p.y;
		}
		double pow_min_len = 1.79769e+308; // double 자료형의 max 값
		// N개 중에서 N/2개의 벡터 뽑아 vector_sum_arr 생성(조합)
		combination(N, N / 2, 0, 0, vector_sum);
		for (int i = 0; i < vector_sum_arr.size(); i++) {
			vector_result.x = all_vector_sum.x - 2 * vector_sum_arr[i].x; // X1 - X2 = (X1 + X2) - 2 * X2
			vector_result.y = all_vector_sum.y - 2 * vector_sum_arr[i].y;
			double pow_len = vector_result.x * vector_result.x + vector_result.y * vector_result.y;
			pow_min_len = min(pow_min_len, pow_len);
		}
		cout << fixed; // 소수점 이하의 자릿수만 변경 가능하게 함
		cout.precision(15); // 소수점 아래 15자리까지 표현
		cout << sqrt(pow_min_len) << "\n"; // answer
		points.clear();
		vector_sum_arr.clear();
	}
	return 0;
}