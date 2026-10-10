#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1;
    cin >> str2;
    
    const int n = str1.size();
    const int m = str2.size();

    vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int remove = i > 0 ? dp[i - 1][j] : j;
            int add = j > 0 ? dp[i][j - 1] : i;
            int replace = i > 0 && j > 0 ? dp[i - 1][j - 1] : max(j, i);

            if (str1[i] == str2[j]) {
                dp[i][j] = replace;
            } else {
                dp[i][j] = min({add, remove, replace}) + 1;
            }
        }
    }

    cout << dp[n - 1][m - 1];
    return 0;
}