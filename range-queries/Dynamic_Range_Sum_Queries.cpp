#include <bits/stdc++.h>
using namespace std;

/*
Observations:
We only need to update at most 1 index in the initial array

Approach: Segment tree decomposition
Another classic template problem
*/

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        nums[i] = x;
    }

    vector<long long> seg(2 * n);
    for (int i = 0; i < n; i++) {
        seg[i + n] = nums[i];
    }
    for (int i = n - 1; i > 0; i--) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }

    for (int i = 0; i < q; i++) {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1) {
            int j = a + n - 1;
            seg[j] = b;
            j /= 2;
            while (j > 0) {
                seg[j] = seg[j * 2] + seg[j * 2 + 1];
                j /= 2;
            }
        }
        else {
            int l = a + n - 1;
            int r = b + n - 1;
            long long res = 0;
            while (l <= r) {
                if (l % 2 == 1) {
                    res += seg[l];
                    l++;
                }
                if (r % 2 == 0) {
                    res += seg[r];
                    r--;
                }

                l /= 2;
                r /= 2;
            }
            cout << res << "\n";
        }
    }

    return 0;
}