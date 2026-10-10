#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if (b > a) swap(a, b);
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
    for (int i = 1; i <= b; i++) {
        dp[i][i] = 0;
    }

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (dp[i][j] != INT_MAX) continue;

            // split horizontally
            for (int k = 1; k < i; k++) {
                int w1 = k;
                int h1 = j;

                int w2 = i - k;
                int h2 = j;
                if (h1 > w1) swap(h1, w1);
                if (h2 > w2) swap(h2, w2);

                dp[i][j] = min(dp[i][j], dp[w1][h1] + dp[w2][h2] + 1);
            }

            // split vertically
            for (int k = 1; k < j; k++) {
                int w1 = i;
                int h1 = k;

                int w2 = i;
                int h2 = j - k;
                if (h1 > w1) swap(h1, w1);
                if (h2 > w2) swap(h2, w2);

                dp[i][j] = min(dp[i][j], dp[w1][h1] + dp[w2][h2] + 1);
            }
        }
    }

    cout << dp[a][b];
    return 0;
}