#include <bits/stdc++.h>
using namespace std;

/*
Observations:
Classic fundamental prefix sum problem

Approach: Prefix sum
*/

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        nums[i] = num;
    }

    vector<long long> psum(n);
    for (int i = 0; i < n; i++) {
        long long last = (i > 0) ? psum[i - 1] : 0;
        psum[i] = last + nums[i];
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        long long l = (a > 0) ? psum[a - 1] : 0;
        long long r = psum[b];
        cout << r - l << "\n";
    }

    return 0;
}