#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;
vector<vector<long long>> multiply(vector<vector<long long>> a, vector<vector<long long>> b) {
    vector<vector<long long>> c(6, vector<long long>(6));

    for (int k = 0; k < 6; k++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }

    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    // identity matrix
    vector<vector<long long>> res(6, vector<long long>(6));
    for (int i = 0; i < 6; i++) res[i][i] = 1;

    /*
    dp[i][0] = sum of all other dimensions
    dp[i][1-5] = takes after the upper dimension (thus dp[1][0] = 1 and etc.)
    */
    vector<vector<long long>> exp = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0}
    };

    while (n > 0) {
        if (n % 2 == 1) {
            res = multiply(res, exp);
        }

        exp = multiply(exp, exp);
        n /= 2;
    }

    cout << res[0][0];
    return 0;
}