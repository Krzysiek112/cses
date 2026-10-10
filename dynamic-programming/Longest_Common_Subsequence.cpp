#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int& num : arr1) {
        cin >> num;
    }
    for (int& num : arr2) {
        cin >> num;
    }

    vector<vector<int>> dp(n, vector<int>(m));
    vector<vector<char>> breadcrumbs(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr1[i] == arr2[j]) {
                dp[i][j] = (i > 0 && j > 0 ? dp[i - 1][j - 1] : 0) + 1;
            } else {
                int top = i > 0 ? dp[i - 1][j] : 0;
                int left = j > 0 ? dp[i][j - 1] : 0;

                dp[i][j] = max(top, left);
                if (top > left) {
                    breadcrumbs[i][j] = 't';
                } else {
                    breadcrumbs[i][j] = 'l';
                }
            }
        }
    }

    cout << dp[n - 1][m - 1] << "\n";
    int i = n - 1;
    int j = m - 1;
    int k = dp[n - 1][m - 1] - 1;
    vector<int> seq(dp[n - 1][m - 1]);
    while (i >= 0 && j >= 0) {
        if (breadcrumbs[i][j] == 't') {
            i--;
        } else if (breadcrumbs[i][j] == 'l') {
            j--;
        } else {
            seq[k] = arr1[i];
            k--;
            i--;
            j--;
        }
    }

    for (int s : seq) {
        cout << s << " ";
    }

    return 0;
}