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
            (init(start, mid, index * 2) * init(mid + 1, end, 1 + index * 2)) % 1000000007;
        return tree[index];
    }
}

long long interval_mul(int start, int end, int index, int left, int right) {
    if (right < start || left > end)
        return 1;
    else if (left <= start && right >= end)
        return tree[index];
    else {
        int mid = (start + end) / 2;
        return (interval_mul(start, mid, index * 2, left, right) *
            interval_mul(mid + 1, end, index * 2 + 1, left, right)) % 1000000007;
    }
}

long long update(int start, int end, int index, int change_index, long long alt_num) {
    if (change_index < start || change_index > end) // out of range
        return tree[index];
    else {
        if (start == end) {
          tree[index] = alt_num;
          return tree[index];
        }
        else {
          int mid = (start + end) / 2;
          tree[index] = update(start, mid, index * 2, change_index, alt_num) * update(mid + 1, end, index * 2 + 1, change_index, alt_num) % 1000000007;
          return tree[index];
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    arr = new long long[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    tree = new long long[4 * n];
    init(0, n - 1, 1);
    int a, b;
    long long c;
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
          update(0, n - 1, 1, b - 1, c);
          /***
          for (int i = 1; i < 4 * n; i++) {
            cout << tree[i] << " ";
          }
          ***/
        }
        else { // when a == 2
            cout << interval_mul(0, n - 1, 1, b - 1, c - 1) << '\n';
        }
    }

    delete[] arr;
    delete[] tree;
    return 0;
}