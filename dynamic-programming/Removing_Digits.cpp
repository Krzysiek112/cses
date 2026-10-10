#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int num = i;
        while (num > 0) {
            int d = num % 10;
            num /= 10;

            if (dp[i - d] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
    }

    cout << dp[n];
    return 0;
}