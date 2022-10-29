#include <iostream>
using namespace std;

long long* arr, * tree;

long long init(int start, int end, int index) {
    if (start == end) {
        tree[index] = arr[start];
        return tree[index];
    }
    else {
        int mid = (start + end) / 2;
        tree[index] =
            init(start, mid, index * 2) + init(mid + 1, end, 1 + index * 2);
        return tree[index];
    }
}

long long interval_sum(int start, int end, int index, int left, int right) {
    if (right < start || left > end)
        return 0;
    else if (left <= start && right >= end)
        return tree[index];
    else {
        int mid = (start + end) / 2;
        return interval_sum(start, mid, index * 2, left, right) +
            interval_sum(mid + 1, end, index * 2 + 1, left, right);
    }
}

void update(int start, int end, int index, int change_index, long long diff) {
    if (change_index < start || change_index > end)
        return;
    else {
        tree[index] += diff;
        if (start == end)
            return;
        else {
            int mid = (start + end) / 2;
            update(start, mid, index * 2, change_index, diff);
            update(mid + 1, end, index * 2 + 1, change_index, diff);
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    arr = new long long[n]();
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    tree = new long long[4 * n]();
    init(0, n - 1, 1);
    int a, b;
    long long c;
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(0, n - 1, 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        }
        else {
            cout << interval_sum(0, n - 1, 1, b - 1, c - 1) << '\n';
        }
    }

    delete[] arr;
    delete[] tree;

    return 0;
}