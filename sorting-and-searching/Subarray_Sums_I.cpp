#include <bits/stdc++.h>
using namespace std;

/*
Observations:
a[i] is always positive (a[i] > 0)

Approach: Sliding Window
maintain two pointers l, r

when the sum of the subarray a[l:r] exceeds x, shrink the window
else broaden the window
*/

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        nums[i] = num; 
    }

    int res = 0;
    int l = 0;
    int s = 0;
    for (int r = 0; r < n; r++) {
        s += nums[r];
        while (l < r && s > x) {
            s -= nums[l];
            l++;
        }

        if (s == x) res++;
    }

    cout << res;
    return 0;
}