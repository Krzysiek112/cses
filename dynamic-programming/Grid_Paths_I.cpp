#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            char tile;
            cin >> tile;

            grid[r][c] = tile;
        }
    }

    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = (grid[0][0] == '*') ? 0 : 1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if ((r == 0 && c == 0) || grid[r][c] == '*') continue;

            int top = (r == 0) ? 0 : dp[r - 1][c];
            int left = (c == 0) ? 0 : dp[r][c - 1];

            dp[r][c] = (top + left) % MOD;
        }
    }

    cout << dp[n - 1][n - 1];
    return 0;
}