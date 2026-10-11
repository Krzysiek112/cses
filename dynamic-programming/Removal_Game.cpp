#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& val : arr) {
        cin >> val;
    }

    vector<vector<long long>> dp(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        dp[i][i] = arr[i];
    }

    for (int l = n - 2; l >= 0; l--) {
        for (int r = l + 1; r < n; r++) {
            dp[l][r] = max(arr[l] - dp[l + 1][r], arr[r] - dp[l][r - 1]);
        }
    }
 
    cout << (dp[0][n - 1] + accumulate(arr.begin(), arr.end(), 0LL)) / 2 << "\n";
    return 0;
}