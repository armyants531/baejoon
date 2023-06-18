#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct point {
	int x, y;
};

bool compare(point p1, point p2) {
	if (p1.x == p2.x) {
		return p1.y < p2.y;
	}
	return p1.x < p2.x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<point> arr;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr.push_back({x, y});	
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i].x << " " << arr[i].y << "\n";
	}
	
	return 0;
}